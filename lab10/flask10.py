#!/usr/bin/python3

from flask import Flask
from flask import request

app = Flask(__name__)

@app.route('/<int:arg1>/<op>/<int:arg2>', methods=['GET'])
def index(arg1, op, arg2):
    if op == '+':
        return str(arg1 + arg2)
    elif op == '-':
        return str(arg1 - arg2)
    elif op == '*':
        return str(arg1 * arg2)
    else:
        return '400 Bad Request'

@app.route('/', methods=['POST'])
def index_post():
    data = request.get_json()
    arg1 = data.get('arg1')
    arg2 = data.get('arg2')
    op = data.get('op')
    if arg1 is None or arg2 is None or op is None:
        return '400 Bad Request'
    if op == '+':
        return str(arg1 + arg2)
    elif op == '-':
        return str(arg1 - arg2)
    elif op == '*':
        return str(arg1 * arg2)
    else:
        return '400 Bad Request'
    
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=10115)