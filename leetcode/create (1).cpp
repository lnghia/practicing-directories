#include <iostream>
#include <pthread.h>
#include <mutex>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using  namespace std;

mutex myLock;

vector<string> ipList;

class Worker {
public:
    void operator()(int IDWorker) {
        while (1) {
            myLock.lock();
            if (ipList.empty()) {
                cout << "worker " << IDWorker << " done!\n";
                myLock.unlock();
                break;
            }    
            cout << "worker " << IDWorker << " process " << ipList.back() << "\n";
            system("ping fb.com");
            ipList.pop_back();
            myLock.unlock();
        }
    }
};

int main() {
    int numThreads = 4;
    // vi du ipList 
    ipList = vector<string>({"1", "2", "3", "4", "5", "6", "7", "8"});
    vector<thread *> threads;
    threads.reserve(numThreads);
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(new thread(Worker(), i));
    }
    for (int i = 0; i < numThreads; ++i) {
        threads[i]->join();
    }
    cout << "\n TIME: " << fixed << setprecision(2) << (double)(clock()) / CLOCKS_PER_SEC * 1000 << " .ms\n";
    return 0;
}