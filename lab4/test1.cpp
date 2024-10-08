#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(){
    int s1 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);//IPPROTO_UDP대신 0을 넣어도 된다.
    cout << "UDP socket ID : " << s1 << endl;
    int s2 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//IPPROTO_TCP대신 0을 넣어도 된다.
    cout << "TCP socket ID : " << s2 << endl;
    close(s1);
    int s3 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//IPPROTO_TCP대신 0을 넣어도 된다.
    cout << "TCP socket ID : " << s3 << endl;//close(s1)으로 인해 s1이 닫혔기 때문에 s3는 s1과 같은 ID를 가진다.
    close(s2);
    close(s3);
    return 0;
}