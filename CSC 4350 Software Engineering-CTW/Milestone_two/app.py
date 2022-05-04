
from flask import flash, redirect, url_for,  render_template, request, redirect, url_for, session
from flask import request

from sqlalchemy import func
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy import exists,delete
from flask_login import UserMixin

import os
import random
import requests
import flask

from dotenv import load_dotenv
load_dotenv()


app = flask.Flask(__name__)
secret_key=os.getenv("SECRET_KEY")
app.secret_key = secret_key


app.config['SQLALCHEMY_DATABASE_URI'] = os.getenv('DATABASE_URL')
# Gets rid of a warning
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

# the name of the database; add path if necessary
db_name = 'sockmarket.db'

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + db_name

app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = True

# this variable, db, will be used for all SQLAlchemy commands

db = SQLAlchemy(app) #pass the app object into the DB
class Person(db.Model, UserMixin):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(20), unique=True, nullable=False)
    password = db.Column(db.String(20))
    rating = db.Column(db.Integer, primary_key=True)
    comment = db.Column(db.String(50)) 
    db.create_all()
    
    
 

    def __init__(self, person, rating):
            self.person = person
            self.rating = rating

            
        
 
@app.route("/login", methods=["POST, GET"])
def login():
    if request.method == "POST":
        session.permanent = True
        user = request.form["nm"]
        session["user"] = user
        
        flash("Login Succesful")
        return redirect(url_for("user"))
    else:
        if "user" in session:
            flash("Already Logged In!")
            return redirect(url_for("user"))
        return render_template("login.html")

@app.route("/signup", methods=["POST, GET"])
if request.method == "POST":
    if not request.form['name'] or not request.form['pin']:
         flash('Please enter all the fields', 'error')
    else
         db.session.add(person())
         db.session.commit()
         flash('Record was successfully added')
         return render_template('main.html')
    
    
@app.route("user", methods=["POST", "Get"])
def user():
    email = None
    if "user" in session:
        user = session["user"]
        
        if request.method == "POST":
            email = request.form["email"]
            session["email"] = email
        
        else:
            if "email" in session:
                email = session["email"]
            
        return render_template("index.html", email=email)
    else:
        flash("Not logged in")
        return redirect(url_for("login"))
    
    
@app.route("/logout4")
def logout():
    flash("You've been logged out")
    session.pop("user", None)
    return redirect(url_for("login"))
    
if __name__ == "__main__":
    app.run(debug=True)

    


