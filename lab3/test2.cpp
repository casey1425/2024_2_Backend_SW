#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(){
    int s = socket(AF_INET, SOCK_STREAM, IPPROTO_UDP);
    cout << "Socket ID: " << s << endl;
    close(s);
    return 0;

    s = socket(AF_INET, SOCK_STREAM, 0);
    cout << "Socket ID: " << s << endl;
    close(s);
    return 0;
}