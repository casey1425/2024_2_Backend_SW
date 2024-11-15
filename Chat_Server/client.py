import socket
import threading
import sys
import json
import errno
import argparse
import message_pb2 as protobuf_pb2

parser = argparse.ArgumentParser(description="Chat Client")
parser.add_argument("--format", choices=["json", "protobuf"], default="json", help="Message format: json or protobuf")
args = parser.parse_args()

message_format = args.format

server_ip = '127.0.0.1'
server_port = 10115
client_ip = '127.0.0.1'
client_port = 20115
client_name = None
room_number = None
room_name = None
client_socket = None

lock = threading.Lock()

def close_socket():
    global client_socket
    with lock:
        if client_socket is not None:
            client_socket.close()
            client_socket = None

def create_socket():
    global client_socket
    close_socket()
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    client_socket.bind((client_ip, client_port))
    client_socket.connect((server_ip, server_port))

create_socket()

def receive_message():
    global client_socket
    while True:
        try:
            data = client_socket.recv(1024)
            if not data:
                break

            if message_format == 'json':
                message = json.loads(data.decode())
            elif message_format == 'protobuf':
                protobuf_message = protobuf_pb2.ChatMessage()
                protobuf_message.ParseFromString(data)
                message = protobuf_message.message

            print(message)
        except ConnectionResetError:
            print('Connection closed by server')
            close_socket()
            break
        except OSError as e:
            if e.errno == errno.EBADF:
                break
            else:
                raise

def send_message(command_type, name=None, room_number=None, room_name=None, message=None):
    global client_socket
    with lock:
        if message_format == 'json':
            message_data = {
                "type": command_type,
                "name": name,
                "room_number": room_number,
                "room_name": room_name,
                "message": message
            }
            client_socket.sendall(json.dumps(message_data).encode())
        elif message_format == 'protobuf':
            protobuf_message = protobuf_pb2.ChatMessage()
            protobuf_message.type = command_type
            if name:
                protobuf_message.name = name
            if room_number:
                protobuf_message.room_number = room_number
            if room_name:
                protobuf_message.room_name = room_name
            if message:
                protobuf_message.message = message
            client_socket.sendall(protobuf_message.SerializeToString())

def handle_name_command(command):
    global client_name
    if client_name is None:
        client_name = command[6:]
        print(f'Your name is {client_name}')
        send_message('/name', name=client_name)
    else:
        print('Your name is already set')

def handle_rooms_command(command):
    send_message('/rooms')

def handle_create_command(command):
    global room_number, room_name
    if room_number is not None:
        print('You are already in a room')
        return
    room_name = command[8:]
    send_message('/create', room_name=room_name)

def handle_join_command(command):
    global room_number
    if room_number is not None:
        print('You are already in a room')
        return
    room_number = command[6:]
    send_message('/join', room_number=room_number)

def handle_leave_command(command):
    global room_number, room_name
    if room_number is None:
        print('You are not in a room')
        return
    send_message('/leave')
    room_number = None
    room_name = None

def handle_shutdown_command(command):
    send_message('/shutdown')
    close_socket()
    sys.exit(0)

def handle_help_command(command):
    print('사용가능 명령어들:')
    print('/name: 채팅 이름을 지정함')
    print('/rooms: 채팅 방 목록을 출력함')
    print('/create: 채팅 방을 만듬')
    print('/join: 채팅 방에 들어감')
    print('/leave: 채팅 방을 나감')
    print('/shutdown: 채팅 서버를 종료함')

def handle_command(command):
    if command.startswith('/name '):
        handle_name_command(command)
    elif command == '/rooms':
        handle_rooms_command(command)
    elif command.startswith('/create '):
        handle_create_command(command)
    elif command.startswith('/join '):
        handle_join_command(command)
    elif command == '/leave':
        handle_leave_command(command)
    elif command == '/shutdown':
        handle_shutdown_command(command)
    elif command == '/help':
        handle_help_command(command)
    else:
        send_message("message", message=command)

def send_name():
    global client_name
    if client_name is not None:
        send_message('/name', name=client_name)

send_name()

def send_room():
    global room_number, room_name
    if room_number is not None:
        send_message('/join', room_number=room_number)
    elif room_name is not None:
        send_message('/create', room_name=room_name)

send_room()

receive_thread = threading.Thread(target=receive_message)
receive_thread.daemon = True
receive_thread.start()

while True:
    command = input()
    handle_command(command)

close_socket()
sys.exit(0)