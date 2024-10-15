#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void f1(){
    cout << "f1 : " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "f1 : woke up" << endl;
}

void f2(int arg){
    cout << "f2: " << arg << endl;
}

int main(){
    auto start = chrono::system_clock::now();
    thread t1; // thread를 만들지 않음
    thread t2(f1); // thread를 만들고 f1을 실행
    thread t3(f2, 10); // thread를 만들고 f2를 실행, 인자로 10을 넘김
    cout << "C++ id : " << t3.get_id() << endl;
    cout << "Native id : " << t3.native_handle() << endl;

    t2.join(); // t2가 종료될 때까지 대기
    t3.join(); // t3가 종료될 때까지 대기

    auto end = chrono::system_clock::now();
    auto duration = end - start;
    auto seconds = chrono::duration_cast<chrono::seconds>(duration).count();
    cout << "Elapsed : " << seconds << endl;

    return 0;
}