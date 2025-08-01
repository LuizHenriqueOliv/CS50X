import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    user = db.execute("SELECT * FROM users WHERE id = (?)", session["user_id"])
    stocks = db.execute("""
        SELECT symbol, SUM(shares) AS total_shares
        FROM transactions
        WHERE user_id = (?)
        GROUP BY symbol
        HAVING total_shares > 0
    """, session["user_id"])
    value_shares = 0.0

    for stock in stocks:
        quote = lookup(stock["symbol"])
        stock["price"] = quote["price"]
        stock["total"] = stock["price"] * stock["total_shares"]
        value_shares += stock["total"]

    total_balance = value_shares + float(user[0]["cash"])

    return render_template("index.html", user=user, stocks=stocks, value_shares=value_shares, total_balance=total_balance)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        stock = lookup(symbol)
        shares = (request.form.get("shares"))

        if not symbol:
            return apology("Must provide a symbol")
        if not stock:
            return apology("Invalid symbol")
        if not shares:
            return apology("Must provide a shares")

        try:
            shares = int(shares)
        except ValueError:
            return apology("Invalid shares")
        if shares <= 0:
            return apology("Invalid shares")

        user = db.execute("SELECT * FROM users WHERE id = (?)", session["user_id"])
        cash = (user[0]["cash"])
        price = float(stock["price"])
        cost = price * shares

        if cash < cost:
            return apology("You dont have enough money")


        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, total, transaction_type) VALUES (?, ?, ?, ?, ?, ?)", session['user_id'], stock["symbol"], shares, price, shares*price, "buy")


        cash -= cost
        db.execute("UPDATE users SET cash = (?) WHERE id = (?)", cash, session["user_id"])

        return redirect("/")
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    stocks = db.execute("SELECT transaction_type, symbol, price, shares, timestamp FROM transactions WHERE user_id = (?) ORDER BY timestamp DESC", session["user_id"])
    return render_template("history.html", stocks=stocks)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        stock = lookup(symbol)

        if not stock:
            return apology("The stock could not be found")
        return render_template("quoted.html", stock=stock)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        # grab username, password and password confirmed
        username_created = request.form.get("username")
        password_created = request.form.get("password")
        password_confirmed = request.form.get("confirmation")

        rows = db.execute("SELECT * FROM users WHERE username = (?)", username_created)
        if rows:
            return apology("This username already exist")

        if not username_created:
            return apology("Please, must provide a username")
        if not password_created:
            return apology("Please, must provide a password")
        if not password_confirmed:
            return apology("Please, comfirm your password")
        if password_created != password_confirmed:
            return apology("Your password is not equal your password confirmed")

        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username_created, generate_password_hash(password_created))
        return redirect("/login")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "POST":
        stocks = db.execute("SELECT symbol FROM transactions WHERE user_id = (?) GROUP BY symbol", session["user_id"])
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Please, choose one stock.")
        if not any(stock["symbol"] == symbol for stock in stocks):
            return apology("You dont have this stock")

        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("Invalid Shares")
        if shares <= 0:
            return apology("Invalid shares")

        user_shares = db.execute("SELECT SUM(shares) AS user_shares FROM transactions WHERE user_id = (?) AND symbol = (?) GROUP BY symbol", session["user_id"], symbol)
        if shares > int(user_shares[0]["user_shares"]):
            return apology("You dont have enough stocks")

        price = lookup(symbol)["price"]
        total = shares * price

        # register the sell
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, total, transaction_type) VALUES (?, ?, ?, ?, ?, ?)", session['user_id'], symbol, -shares, price, -(total), "sell")
        # update the user cash after sell
        db.execute("UPDATE users SET cash = cash + (?) WHERE id = (?)", total, session["user_id"])

        return redirect("/")
    else:
        stocks = db.execute("SELECT symbol FROM transactions WHERE user_id = (?) GROUP BY symbol HAVING SUM(shares) > 0", session["user_id"])
        return render_template("sell.html", stocks=stocks)


@app.route("/deposit", methods=["GET", "POST"])
@login_required
def deposit():
    if request.method == "POST":
        deposit = request.form.get("deposit")
        if not deposit:
            return apology("Must provide a value to deposit")

        try:
            if float(deposit) <= 0:
                return apology("The minimum deposit is 1 dollar")
        except ValueError:
            return apology("Invalid value")

        db.execute("UPDATE users SET cash = cash + (?) WHERE id = (?)", deposit, session["user_id"])
        return redirect("/")
    else:
        return render_template("deposit.html")

@app.route("/withdraw", methods=["GET", "POST"])
@login_required
def withdraw():
    if request.method == "POST":
        withdraw = request.form.get("withdraw")
        if not withdraw:
            return apology("Must provide a value to withdraw")
        try:
            if float(withdraw) <= 0:
                return apology("The minimum to withdraw is 1 dollar")
        except ValueError:
            return apology("Invalid Value")

        user_cash = db.execute("SELECT cash FROM users WHERE id = (?)", session["user_id"])
        if float(withdraw) > float(user_cash[0]["cash"]):
            return apology("You dont have this money to withdraw")

        db.execute("UPDATE users SET cash = cash - (?) WHERE id = (?)", withdraw, session["user_id"])
        return redirect("/")
    else:
        return render_template("withdraw.html")
