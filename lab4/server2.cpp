#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(){
    int passiveSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(passiveSocket < 0){
        cerr << "socket() failed : " << strerror(errno) << endl;
        return 1;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(10115);
    if (bind(passiveSocket, (struct sockaddr*)&sin, sizeof(sin)) < 0){
        cerr << "bind() failed : " << strerror(errno) << endl;
        return 1;
    }
    if (listen(passiveSocket, 10) < 0){
        cerr << "listen() failed : " << strerror(errno) << endl;
        return 1;
    }
    while (true){
        struct sockaddr_in clientAddr;
        memset(&clientAddr, 0, sizeof(clientAddr));
        unsigned int clientAddrLen = sizeof(clientAddr);

        int clientSock = accept(passiveSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSock < 0){
            cerr << "accept() failed : " << strerror(errno) << endl;
            continue;
        }
    

    char buf[65536];
    int numRecv = recv(clientSock, buf, sizeof(buf), 0);
    if (numRecv == 0){
        cout << "Socket closed : " << clientSock << endl;
    } else if (numRecv < 0){
        cerr << "recv() failed : " << strerror(errno) << endl;
    } else{
        cout << "Received " << numRecv << " bytes, clientSock" << clientSock << endl;
    }
    int offset = 0;
    while (offset < numRecv){
        int numSend = send(clientSock, buf + offset, numRecv - offset, 0);
        if (numSend < 0){
            cerr << "send() failed : " << strerror(errno) << endl;
        } else {
            cout << "Sent " << numSend << " bytes" << endl;
            offset += numSend;
        }
    }
    close(clientSock);
    }
    close(passiveSocket);
}