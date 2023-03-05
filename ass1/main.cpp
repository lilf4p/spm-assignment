#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#define N 10000
#define DIM_VECTOR 100000
#define NUM_THREADS 10
#define VERBOSE 0

using namespace std;

//vector of int initially all 0 
//take value from command line 
//compute a function for all the input and put into vector
//use thread to divide vector into threads

//compute the time and see if it is faster than sequentially

//define a start and a end index for each thread -> each thread compute the new value for vector indexes only in the range assigned 

//use utimer() to measure the time

void thread_function(int start, int end, vector<int> &v);
void test();

int main(int, char**) {

    //take number of threads to parallelize from input
    int num_threads = NUM_THREADS;
    cout << "Enter the number of threads: "<< endl;
    cin >> num_threads;

    //vector initialization
    vector<int> v;
    int i=0;
    for (i=0; i < DIM_VECTOR; i++) {
        v.push_back(0);
    }

    //sequential computation
    cout << "-------Sequential computation-------" << endl;
    auto t_start = chrono::steady_clock::now();
    for (i=0; i < DIM_VECTOR; i++) {
        for (int j=0; j < N; j++) {
            v.at(i) += 1;
        }
    }
    auto t_end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = t_end-t_start;
    cout << "-------Elapsed time: " <<  elapsed_seconds.count() << "s-------" <<endl;

    //parallel computation
    cout << "-------Parallel computation--------" << endl;
    auto t2_start = chrono::steady_clock::now();
    int step = DIM_VECTOR / num_threads;
    vector <thread> threads;
    i=0;
    //start all threads
    while (i<DIM_VECTOR) {
        //launch thread with start and end index
        //ogni thread prende DIM_VECTOR/num_threads elementi del vettore

        //compute index
        int end;
        if (i+step > DIM_VECTOR) {
            end = DIM_VECTOR;
        }else{
            end = i + step;
        }
        if (VERBOSE) cout << "Thread -> Start:" << i << " End:" << end << endl;

        //launch thread
        //thread t(thread_function,i,end,ref(v));  
        threads.push_back(thread(thread_function,i,end,ref(v)));

        i = i + step;
    }
    //wait for threads to finish
    for (int k=0; k < num_threads; k++) {
        threads[k].join();
        if (VERBOSE) cout << "Joined thread " << k << endl;
    }
    auto t2_end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds2 = t2_end-t2_start;
    cout << "-------Elapsed time: " <<  elapsed_seconds2.count() << "s-------" <<endl;

}

void thread_function(int start, int end, vector<int> &v) {
    //processa end-start elementi del vettore 
    for (int i = start; i < end; i++) {
        //incremento di N
        for (int j = 0; j < N; j++) {
           v.at(i) += 1;
        }
    }
}

void test() {
    cout << "Hello World!" << endl;
}

