#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int sum = 0;
mutex m;

void f(){
    for (int i = 0; i < 10 * 1000 * 1000; ++i){
        unique_lock<mutex> ul(m);//ul을 빼먹으면 안댐
        ++sum;
    }
}

int main(){
    thread t(f);
    for (int i = 0; i < 10 * 1000 * 1000; ++i){
        unique_lock<mutex> ul(m);
        ++sum;
    }
    t.join();
    cout << "sum : " << sum << endl;
}
// mutex를 사용하지 않았을때는 sum이 20,000,000이 아닌 다른 값이 나왔다.
// mutex를 사용하면 sum이 20,000,000이 나온다.