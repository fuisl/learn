from flask import Flask, render_template

app = Flask(__name__)  # create a new Flask instance


@app.route("/")  # define the default route
def index():
    return render_template("index.html")