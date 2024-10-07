#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s < 0) return 1;

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(10000);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    string buf;
    char buf2[65536];
    socklen_t sin_size = sizeof(sin);

    while (true) {
        cout << "Enter message: ";
        if (!getline(cin, buf)) {
            break;
        }

        int numBytesSent = sendto(s, buf.c_str(), buf.length(), 0, (struct sockaddr*)&sin, sizeof(sin));
        cout << "Sent: " << numBytesSent << endl;

        int numBytesReceived = recvfrom(s, buf2, sizeof(buf2), 0, (struct sockaddr*)&sin, &sin_size);
        if (numBytesReceived > 0) {
            buf2[numBytesReceived] = '\0';
            cout << "Received: " << numBytesReceived << endl;
            cout << "From: " << inet_ntoa(sin.sin_addr) << endl;
            cout << buf2 << endl;
        }
    }

    close(s);
    return 0;
}