#include <iostream>
#include <thread>
#include <unistd.h> 
#include "utils.h"

using namespace std;

int main(int argc, char** argv) {
    
    //launch a pool of threads
    thread thread_array[10];

    for (int i = 0; i < 10; i++) {
        thread_array[i] = thread(increase_atomic,i);
    }

    for (int i = 0; i < 10; i++) {
        thread_array[i].join();
        cout << "Thread " << i << " is done" << endl;
    }

    return 0;
}