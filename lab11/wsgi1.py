def application(environ, start_response): #Callable
    print(environ['REQUEST_METHOD'])
    print(environ['PATH_INFO'])

    status = '200 OK'
    headers = [('Content-type', 'text.html')] #header는 여러개가 올 수 있으므로 list로 받음

    start_response(status, headers)
    return [b'Hello World']