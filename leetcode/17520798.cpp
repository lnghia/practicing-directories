#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using  namespace std;

mutex myLock;

vector<string> ipList;
vector<string> pingableIPs, unpingableIPs;
int threadNums, ipNums;

bool isPingable(string &ip){
    return !system(("ping "+ip + " > nul").c_str());
}

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
            if(isPingable(ipList.back())){
                pingableIPs.push_back(ipList.back());
            }
            else{
                unpingableIPs.push_back(ipList.back());
            }
            ipList.pop_back();

            myLock.unlock();
        }
    }
};

void input(){
    cout << "Enter the number of IP: ";
    cin >> ipNums;
    cout << "Enter the number of thread: ";
    cin >> threadNums;
}

void initIPList(){
    int i=1;
    string ip;

    while(ipNums--){
        cout << "Enter IP number " << i++ << ": ";
        cin >> ip;

        ipList.push_back(ip);
    }
}

void output(){
    cout << "Number of ip: " << ipList.size() << '\n';
    cout << "Number of thread: " << threadNums << '\n';
    
    cout << "Pingable ip:\n";
    for(string ip : pingableIPs){
        cout << "- " << ip << '\n';
    }

    cout << "Unpingable ip:\n";
    for(string ip : unpingableIPs){
        cout << "- " << ip << '\n';
    }

    cout << "TIME: " << fixed << setprecision(2) << (double)(clock()) / CLOCKS_PER_SEC << " .s\n";
}

int main() {
    vector<thread *> threads;

    input();
    initIPList();

    threads.reserve(threadNums);
    for (int i = 0; i < threadNums; ++i) {
        threads.push_back(new thread(Worker(), i));
    }

    for (int i = 0; i < threadNums; ++i) {
        threads[i]->join();
    }

    output();

    return 0;
}