from flask import Flask, render_template, request
from flask_session import Session
from werkzeug.security import generate_password_hash, check_password_hash
from cs50 import SQL

app = Flask(__name__)

# session config
app.config["SESSION PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# connect database
db = SQL("sqlite:///vault.db")


@app.route("/")
def index():
    if "user_id" not in session:
        return redirect("/login")
    return "usuário logado"


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        return "TODO"
    else:
        return render_template("register.html")
