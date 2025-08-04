from flask import Flask, render_template, request, redirect, session
from flask_session import Session
from werkzeug.security import generate_password_hash, check_password_hash
from cs50 import SQL
from helpers import login_required
import secrets

app = Flask(__name__)

# session config
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
app.secret_key = secrets.token_hex(16)
Session(app)

# connect database
db = SQL("sqlite:///vault.db")


@app.route("/")
@login_required
def index():
    return "usuário logado"


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        password_confirm = request.form.get("password_confirm")

        if not username or not password or not password_confirm:
            return "Preencha todos os campos"

        if password != password_confirm:
            return "Confirme sua senha corretamente"

        hash_ = generate_password_hash(password)

        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash_)
        except:
            return "Este usuário já existe."

        user = db.execute("SELECT id FROM users WHERE username = (?)", username)
        session["user_id"] = user[0]["id"]
        return redirect("/")

    else:
        return render_template("register.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    session.clear()

    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")

        if not username or not password:
            return "Preencha todos os campos"

        user = db.execute("SELECT * FROM users WHERE username = (?)", username)
        if len(user) != 1 or not check_password_hash(user[0]["hash"], password):
            return "Usuário e/ou Senha inválida"


        session["user_id"] = user[0]["id"]
        return redirect("/")
    else:
        return render_template("login.html")
