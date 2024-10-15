#include <iostream>
#include <thread>

using namespace std;

void f1(){
    cout << "f1" << endl;
}

void f2(int arg){
    cout << "f2: " << arg << endl;
}

int main(){
    thread t1; // thread를 만들지 않음
    thread t2(f1); // thread를 만들고 f1을 실행
    thread t3(f2, 10); // thread를 만들고 f2를 실행, 인자로 10을 넘김
    cout << "C++ id : " << t3.get_id() << endl;
    cout << "Native id : " << t3.native_handle() << endl;

    t2.join(); // t2가 종료될 때까지 대기
    t3.join(); // t3가 종료될 때까지 대기

    return 0;
}