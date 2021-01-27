#Imports
from flask import Flask, render_template, request
from wtforms import Form, TextField, TextAreaField, validators, StringField, SubmitField
import pandas as pd

app = Flask(__name__)


class ReviewForm(Form):
   fname = TextField("First Name", validators=[validators.DataRequired()])
   product = TextField("Product Name", validators=[validators.DataRequired()])
   review= TextAreaField("Your Review", validators=[validators.DataRequired()])
   submit= SubmitField("Submit")


@app.route("/", methods=["GET", "POST"])
def Review():
   form = ReviewForm(request.form)

   
   df = pd.read_csv("reviews.csv", index_col=False, delimiter=',')

   if request.method == "POST":
      result = request.form
      df = df.append({"fname":result["fname"], "product":result["product"], "review":result["review"]}, ignore_index=True)
      df.to_csv("reviews.csv", index=False)

   rev = [] 
   for index, row in df.iterrows():
      rev.append([row["fname"], row["product"], row["review"]])
   rev = rev[::-1] 

   return render_template("index.html", form=form, rev=rev)
    
if __name__ == "__main__":
   app.debug = True
   app.run(host="localhost", port=5000)