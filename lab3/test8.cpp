#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        return 1;
    }
    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(10115);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(s, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        close(s);
        return 1;
    }

    cout << "Echo server 실행중" << endl;

    while (true) {
        char buf[65536];
        socklen_t client_addr_len = sizeof(client_addr);
        
        int numBytes = recvfrom(s, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&client_addr, &client_addr_len);
        if (numBytes < 0) {
            cerr << "Error" << endl;
            continue;
        }

        buf[numBytes] = '\0';
        int sentBytes = sendto(s, buf, numBytes, 0, (struct sockaddr*)&client_addr, client_addr_len);
        if (sentBytes < 0) {
            cerr << "Error" << endl;
        } else {
            cout << "Sent : " << buf << endl;
        }
    }
    close(s);
    return 0;
}