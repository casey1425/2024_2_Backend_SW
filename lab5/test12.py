import json
import socket
import threading

def udp_server():
    UDP_IP = "127.0.0.1"
    UDP_PORT = 10001
    
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((UDP_IP, UDP_PORT))

    print(f"[SERVER] Listening for data on {UDP_IP}:{UDP_PORT}...")

    while True:
        data, sender = sock.recvfrom(65536)
        print(f"[SERVER] Received message from {sender}: {data.decode()}")

        try:
            obj2 = json.loads(data.decode())
        except json.JSONDecodeError as e:
            print(f"[SERVER] Failed to decode JSON: {e}")
            continue

        print(f"[SERVER] Name: {obj2['name']}, ID: {obj2['id']}, Address: {obj2['work']['address']}")

def udp_client():
    UDP_IP = "127.0.0.1"
    UDP_PORT = 10001

    obj1 = {
        'name': 'MJ Kim',
        'id': 12345678,
        'work': {
            'name': 'Myongji University',
            'address': '116 Myongji-ro'
        }
    }

    s = json.dumps(obj1)

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    sock.sendto(bytes(s, encoding='utf-8'), (UDP_IP, UDP_PORT))
    print(f"[CLIENT] Sent data to {UDP_IP}:{UDP_PORT}")

if __name__ == '__main__':
    server_thread = threading.Thread(target=udp_server)
    server_thread.daemon = True
    server_thread.start()

    udp_client()