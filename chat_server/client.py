import socket
import json
import threading
import queue
import select
import argparse
from google.protobuf.message import DecodeError
from enum import Enum
from concurrent.futures import ThreadPoolExecutor

class MessageFormat(Enum):
    JSON = "json"
    PROTOBUF = "protobuf"

class ChatServer:
    def __init__(self, ip, port, format, max_workers=4):
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind((ip, port))
        self.server_socket.listen()
        self.format = format
        self.clients = {}
        self.rooms = {}
        self.client_queue = queue.Queue()
        self.lock = threading.Lock()
        self.executor = ThreadPoolExecutor(max_workers=max_workers)
        self.handlers = {
            "/name": self.handle_name,
            "/rooms": self.handle_rooms,
            "/create": self.handle_create,
            "/join": self.handle_join,
            "/leave": self.handle_leave,
            "/shutdown": self.handle_shutdown,
        }

    def start(self):
        print("Server started and waiting for connections...")
        while True:
            read_sockets, _, _ = select.select([self.server_socket], [], [], 1)
            for sock in read_sockets:
                client_socket, client_address = sock.accept()
                print(f"New connection from {client_address}")
                self.executor.submit(self.client_worker, client_socket, client_address)

    def client_worker(self, client_socket, client_address):
        nickname = f"{client_address}"
        self.clients[client_socket] = nickname
        self.send_message(client_socket, f"[시스템 메시지] 클라이언트가 연결되었습니다: {nickname}")
        try:
            while True:
                message_data = self.receive_message(client_socket)
                if message_data:
                    self.client_queue.put((client_socket, message_data))
                    self.process_queue()
        finally:
            client_socket.close()
            del self.clients[client_socket]

    def process_queue(self):
        while not self.client_queue.empty():
            client_socket, message_data = self.client_queue.get()
            command = message_data.get("command")
            if command in self.handlers:
                self.handlers[command](client_socket, message_data)

    def send_message(self, client_socket, message):
        if self.format == MessageFormat.JSON:
            client_socket.send(json.dumps({"type": "system", "content": message}).encode('utf-8'))
        elif self.format == MessageFormat.PROTOBUF:
            proto_message = myproto_pb2.SystemMessage(content=message)
            client_socket.send(proto_message.SerializeToString())

    def receive_message(self, client_socket):
        try:
            data = client_socket.recv(1024)
            if self.format == MessageFormat.JSON:
                return json.loads(data.decode('utf-8'))
            elif self.format == MessageFormat.PROTOBUF:
                proto_message = myproto_pb2.ClientMessage()
                proto_message.ParseFromString(data)
                return {"command": proto_message.command, "content": proto_message.content}
        except (json.JSONDecodeError, DecodeError):
            return None

    def handle_name(self, client_socket, message_data):
        new_name = message_data["content"]
        with self.lock:
            self.clients[client_socket] = new_name
        self.send_message(client_socket, f"[시스템 메시지] 이름이 {new_name}으로 변경되었습니다.")

    def handle_rooms(self, client_socket, message_data):
        with self.lock:
            rooms_list = [{"room_number": i, "title": room['title'], "members": [self.clients[m] for m in room['members']]} for i, room in self.rooms.items()]
        self.send_message(client_socket, rooms_list if rooms_list else "[시스템 메시지] 개설된 대화방이 없습니다.")

    def handle_create(self, client_socket, message_data):
        title = message_data["content"]
        with self.lock:
            if any(client_socket in room['members'] for room in self.rooms.values()):
                self.send_message(client_socket, "[시스템 메시지] 대화 방에 있을 때는 방을 개설할 수 없습니다.")
                return
            room_id = len(self.rooms) + 1
            self.rooms[room_id] = {'title': title, 'members': [client_socket]}
        self.send_message(client_socket, f"[시스템 메시지] 방제[{title}] 방에 입장했습니다.")

    def handle_join(self, client_socket, message_data):
        room_number = int(message_data["content"])
        with self.lock:
            if room_number not in self.rooms:
                self.send_message(client_socket, "[시스템 메시지] 대화방이 존재하지 않습니다.")
                return
            if any(client_socket in room['members'] for room in self.rooms.values()):
                self.send_message(client_socket, "[시스템 메시지] 대화 방에 있을 때는 다른 방에 들어갈 수 없습니다.")
                return
            self.rooms[room_number]['members'].append(client_socket)
        self.send_message(client_socket, f"[시스템 메시지] 방제[{self.rooms[room_number]['title']}] 방에 입장했습니다.")

    def handle_leave(self, client_socket, message_data):
        with self.lock:
            for room_id, room in self.rooms.items():
                if client_socket in room['members']:
                    room['members'].remove(client_socket)
                    self.send_message(client_socket, f"[시스템 메시지] 방제[{room['title']}] 대화 방에서 퇴장했습니다.")
                    return
            self.send_message(client_socket, "[시스템 메시지] 현재 대화방에 들어가 있지 않습니다.")

    def handle_shutdown(self, client_socket, message_data):
        self.send_message(client_socket, "[시스템 메시지] 서버가 종료됩니다.")
        self.executor.shutdown(wait=True)
        self.server_socket.close()
        sys.exit(0)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("ip", help="IP address of the server.")
    parser.add_argument("port", type=int, help="Port number to connect to.")
    parser.add_argument("--format", choices=["json", "protobuf"], default="json", help="Message format (default: json)")
    args = parser.parse_args()

    format = MessageFormat.JSON if args.format == "json" else MessageFormat.PROTOBUF
    server = ChatServer(args.ip, args.port, format)
    server.start()

if __name__ == "__main__":
    main()