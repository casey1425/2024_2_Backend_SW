#include <atomic>
#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

const int NO_JOB = -1;

atomic<bool> quit(false);

mutex queMutex;
condition_variable queFillable;
condition_variable queFilled;
int que[1] = { NO_JOB };

void producer() {
  cout << "Producer starting. Thread id: " << this_thread::get_id() << endl;

  while (quit.load() == false) {
    int job = rand() % 100;{
        unique_lock<mutex> ul(queMutex);//mutex lock
    while (que[0] != NO_JOB) {
      queFillable.wait(ul);
      }
    que[0] = job;
    queFilled.notify_one();
    cout << "Produced: " << job << endl;
    }
  }
  cout << "Producer finished" << endl;
}

void consumer() {
  cout << "Consumer starting. Thread id: " << this_thread::get_id() << endl;

  while (quit.load() == false) {
    int job;{
        unique_lock<mutex> ul(queMutex);//mutex lock
        while (que[0] == NO_JOB) {
            queFilled.wait(ul);
            }
    job = que[0];
    que[0] = NO_JOB;
    queFilled.notify_one();
    cout << "Consumed: " << job << endl;
    }
  }
  cout << "Consumer finshed" << endl;
}


int main() {
  cout << "Main thread started. Thread id: " << this_thread::get_id() << endl;

  srand(time(NULL));

  thread t1(producer);
  thread t2(consumer);
  thread t3(consumer);

  this_thread::sleep_for(chrono::seconds(5));
  quit.store(true);

  if (t1.joinable()) {
    t1.join();
  }

  if (t2.joinable()) {
    t2.join();
  }

  if (t3.joinable()) {
    t3.join();
  }

  cout << "Main thread finished" << endl;
}