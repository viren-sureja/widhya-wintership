from flask import (Flask, abort, jsonify, make_response, render_template,
                   request)
from flask_httpauth import HTTPBasicAuth

auth = HTTPBasicAuth()
app = Flask(__name__)



users = [
   {
      'id': 1,
      'name': 'Viren Sureja',
      'phone': '6********0',
      'verified': True
   },
   {
      'id': 2,
      'name': 'Prem Koradiya',
      'phone': '9********0',
      'verified': False
   }
]


verified_users = {
    "viren": "hello",
    "parth": "bye"
}

@auth.get_password
def get_pw(username):
    if username in verified_users:
        return verified_users.get(username)
    return None


# home page
@app.route('/', methods=['GET'])
@auth.login_required
def home():
   return render_template('home.html')


# list of all users
@app.route('/userbook/api/users', methods=['GET'])
@auth.login_required
def get_users():
   return jsonify({'users': users})


# list of required user
@app.route('/userbook/api/users/<int:user_id>', methods=['GET'])
@auth.login_required
def get_parti_user(user_id):
   user_details = [user for user in users if user['id'] == user_id]
   if len(user_details)==0:
      abort(404)
   return jsonify({'user': user_details[0]})

#convert html error to json    
@app.errorhandler(404)
def not_found(error):
    return make_response(jsonify({'error': 'We are very sorry, data required by you is not available'}), 404)

# adding new user to user book
@app.route('/userbook/api/users', methods=['POST'])
def newUserEntry():
   if not request.json or not 'name' in request.json:
      abort(400)
   user = {
      'id': users[-1]['id'] + 1,
      'name': request.json['name'],
      'phone': request.json['phone'],
      'verified': False
   }
   verified_users.append({request.json['name']:"hello"})
   users.append(user)
   return jsonify({'user': user}), 201


# updating info of user book
@app.route('/userbook/api/users/<int:user_id>', methods=['PUT'])
@auth.login_required
def update_user(user_id):
   for user in users:
      if user['id']==user_id: 
         if request.json['name'] != None: 
            user['name'] = request.json['name']
         if request.json['phone'] != None: 
            user['phone'] = request.json['phone']
         if request.json['verified'] != None: 
            user['verified'] = request.json['verified']
   return "successfully updated"

# deleting the user from user book
@app.route('/userbook/api/users/<int:user_id>', methods=['DELETE'])
@auth.login_required
def delete_user(user_id):
   for user in users:
      if user['id']==user_id:
         users.remove(user)
   return "successfully deleted"


if __name__ == '__main__':
    app.run(debug=True)
