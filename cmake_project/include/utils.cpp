#include <unistd.h>
#include "utils.h"
#include <iostream>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;

void prova (int arg) {
    cout << "Thread " << arg << " started" << endl;
}

void increase_atomic (int arg) {
    mtx.lock();
    counter++;
    cout << "Thread" << arg << ":" << counter << endl;
    mtx.unlock();
}
