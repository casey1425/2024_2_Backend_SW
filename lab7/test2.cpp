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
    int job = rand() % 100;
    if (que[0] == NO_JOB) {
      que[0] = job;
    }
  }
  cout << "Producer finished" << endl;
}

void consumer() {
  cout << "Consumer starting. Thread id: " << this_thread::get_id() << endl;

  while (quit.load() == false) {
    int job;
    job = que[0];
    que[0] = NO_JOB;
  }
  cout << "Consumer finshed" << endl;
}


int main() {
  cout << "Main thread started. Thread id: " << this_thread::get_id() << endl;

  srand(time(NULL));

  thread t1(producer);
  thread t2(consumer);

  this_thread::sleep_for(chrono::seconds(5));
  quit.store(true);

  if (t1.joinable()) {
    t1.join();
  }

  if (t2.joinable()) {
    t2.join();
  }

  cout << "Main thread finished" << endl;
}