from http import HTTPStatus
import random
import requests
import json
import urllib

from flask import abort, Flask, make_response, render_template, Response, redirect, request

app = Flask(__name__)


naver_client_id = 'CgG1OtWGkcc2Tddx1IJD'
naver_client_secret = '3DWN7tK9Ql'
naver_redirect_uri = 'http://mjubackend.duckdns.org:10115/auth'


@app.route('/')
def home():
    userId = request.cookies.get('userId', default=None)
    name = None

    if userId:
        import sqlite3
        conn = sqlite3.connect('memo.db')
        cursor = conn.cursor()
        try:
            cursor.execute('SELECT name FROM users WHERE user_id=?', (userId,))
            name = cursor.fetchone()
            if name:
                name = name[0]
            else:
                name = None
        except Exception as e:
            print(f"Error: {e}")
            name = None
        finally:
            conn.close()
    return render_template('index.html', name=name)

@app.route('/login')
def onLogin():
    params={
            'response_type': 'code',
            'client_id': naver_client_id,
            'redirect_uri': naver_redirect_uri,
            'state': random.randint(0, 10000)
        }
    urlencoded = urllib.parse.urlencode(params)
    url = f'https://nid.naver.com/oauth2.0/authorize?{urlencoded}'
    return redirect(url)

@app.route('/auth')
def onOAuthAuthorizationCodeRedirected():

    authorization_code = request.args.get('code')
    state = request.args.get('state')
    if not authorization_code or not state:
        abort(HTTPStatus.BAD_REQUEST)
    url = 'https://nid.naver.com/oauth2.0/token'
    headers = {
        'Content-Type': 'application/x-www-form-urlencoded'
    }
    data = {
        'grant_type': 'authorization_code',
        'client_id': naver_client_id,
        'client_secret': naver_client_secret,
        'code': authorization_code,
        'state': state
    }
    response = requests.post(url, headers=headers, data=data)
    if response.status_code != HTTPStatus.OK:
        abort(HTTPStatus.INTERNAL_SERVER_ERROR)
    response = response.json()
    access_token = response.get('access_token')
    if not access_token:
        abort(HTTPStatus.INTERNAL_SERVER_ERROR)

    url = 'https://openapi.naver.com/v1/nid/me'
    headers = {
        'Authorization': f'Bearer {access_token}'
    }
    response = requests.get(url, headers=headers)
    if response.status_code != HTTPStatus.OK:
        abort(HTTPStatus.INTERNAL_SERVER_ERROR)
    response = response.json()
    user_id = response.get('response').get('id')
    user_name = response.get('response').get('name')
    if not user_id or not user_name:
        abort(HTTPStatus.INTERNAL_SERVER_ERROR)

    user_id = None
    user_name = None
    
    response = redirect('/')
    response.set_cookie('userId', user_id)
    return response


@app.route('/memo', methods=['GET'])
def get_memos():
    userId = request.cookies.get('userId', default=None)
    if not userId:
        return redirect('/')

    result = []

    return {'memos': result}


@app.route('/memo', methods=['POST'])
def post_new_memo():
    userId = request.cookies.get('userId', default=None)
    if not userId:
        return redirect('/')

    if not request.is_json:
        abort(HTTPStatus.BAD_REQUEST)

    memo = request.json.get('memo', None)
    if not memo:
        abort(HTTPStatus.BAD_REQUEST)

    return '', HTTPStatus.CREATED
    return '', HTTPStatus.OK


if __name__ == '__main__':
    app.run('0.0.0.0', port=10115, debug=True)