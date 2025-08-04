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
        username = request.form.get("username")
        password = request.form.get("password")
        password_confirm = request.form.get("password_confirm")

        if not username or not password or not password_confirm:
            return "Preencha todos os campos"

        if password != password_confirm:
            return "Confirme sua senha corretamente"

        hash_ = generate_password_hash(password)

        try:
            db.execute("INSERT INTO users (username, hash) VALUES ((?), (?))" username, hash_)
        except:
            return "Este usuário já existe."

        return "Usuário cadastrado com sucesso"

    else:
        return render_template("register.html")
