import json

def application(environ, start_response): #Callable
    print(environ['REQUEST_METHOD'])
    print(environ['PATH_INFO'])

    body_bytes = environ['wsgi.input'].read()
    body_str = body_bytes.decode('utf-8')
    body_json = json.loads(body_str)

    status = '200 OK'
    headers = [('Content-type', 'text.html')] #header는 여러개가 올 수 있으므로 list로 받음

    start_response(status, headers)

    response = f'Hello World {body_json["name"]}'
    return [bytes(response, encoding='utf-8')]