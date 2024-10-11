#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "person.pb.h"

using namespace std;
using namespace mju;

void startServer() {
    int server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket < 0) {
        cerr << "Socket creation failed." << endl;
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Accept from any IP
    server_addr.sin_port = htons(10001);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        cerr << "Bind failed." << endl;
        close(server_socket);
        exit(1);
    }

    char buffer[65536];
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    
    cout << "Server is listening on port 10001..." << endl;

    while (true) {
        int num_bytes = recvfrom(server_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &client_addr_size);
        if (num_bytes < 0) {
            cerr << "Receive failed." << endl;
            continue;
        }

        sendto(server_socket, buffer, num_bytes, 0, (struct sockaddr*)&client_addr, client_addr_size);
    }

    close(server_socket);
}

void startClient() {
    Person *p = new Person();
    p->set_name("MJ Kim");
    p->set_id(12345678);

    Person::PhoneNumber* phone = p->add_phones();
    phone->set_number("010-111-1234");
    phone->set_type(Person::MOBILE);

    phone = p->add_phones();
    phone->set_number("02-100-1000");
    phone->set_type(Person::HOME);

    const string serializedData = p->SerializeAsString();
    cout << "Serialized data length: " << serializedData.length() << endl;

    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s < 0) {
        cerr << "Socket creation failed." << endl;
        return;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(10001);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    int numBytes = sendto(s, serializedData.c_str(), serializedData.length(), 0, (struct sockaddr*)&sin, sizeof(sin));
    cout << "Sent " << numBytes << " bytes." << endl;

    char buffer[65536];
    socklen_t sin_size = sizeof(sin);
    numBytes = recvfrom(s, buffer, sizeof(buffer), 0, (struct sockaddr*)&sin, &sin_size);
    cout << "Received " << numBytes << " bytes." << endl;

    string receivedData(buffer, numBytes); 
    cout << "From " << inet_ntoa(sin.sin_addr) << endl;

    Person *p2 = new Person();
    if (!p2->ParseFromString(receivedData)) {
        cerr << "Failed to parse received data." << endl;
        close(s);
        return;
    }

    cout << "Name: " << p2->name() << endl;
    cout << "ID: " << p2->id() << endl;
    for (int i = 0; i < p2->phones_size(); ++i) {
        cout << "Phone Type: " << p2->phones(i).type() << endl;
        cout << "Phone Number: " << p2->phones(i).number() << endl;
    }

    close(s);
    delete p;
    delete p2;
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "server") == 0) {
        startServer(); 
    } else {
        startClient();
    }
    return 0;
}