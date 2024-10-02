#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        cerr << "Socket creation failed!" << endl;
        return 1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(10000);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    string input;
    
    while (getline(cin, input)) {
        stringstream ss(input);
        string word;

        while (ss >> word) {
            int numBytes = sendto(s, word.c_str(), word.length(), 0, (struct sockaddr*)&sin, sizeof(sin));
            if (numBytes < 0) {
                cerr << "Error sending message!" << endl;
                continue;
            }

            cout << "Sent: " << numBytes << endl;
            char buf2[65536];
            socklen_t sin_size = sizeof(sin);
            numBytes = recvfrom(s, buf2, sizeof(buf2) - 1, 0, (struct sockaddr*)&sin, &sin_size);

            if (numBytes > 0) {
                buf2[numBytes] = '\0';
                cout << "Received: " << numBytes << endl;
                cout << "From: " << inet_ntoa(sin.sin_addr) << endl;
                cout << buf2 << endl;
            } else {
                cerr << "Error receiving message!" << endl;
            }
        }
    }
    close(s);
    return 0;
}