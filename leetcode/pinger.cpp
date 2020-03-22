#include <bits/stdc++.h>
//#include <Windows.h>
#include <atomic>
#include <thread>
#include <time.h>
#include <mutex>

using namespace std;

atomic<int> currentProcessedIPIndex(0);
vector<string> ipList;
atomic<int> _count(0);
vector<string> pingableIPs, unPingableIPs;
vector<thread> threadList;
//vector<int> index;

void input(int &ipNums, int &threadNums){
    cout << "Enter the number of IP: ";
    cin >> ipNums;
    
    cout << "Enter the number of thread: ";
    cin >> threadNums;
}

void initIPList(int ipNums){
    vector<string> ips;
    int i=1;
    string ip;

    while(ipNums--){
        cout << "Enter IP number " << i++ << ": ";
        cin >> ip;

        ipList.push_back(ip);
    }

    _count=ipList.size();
}

bool ping(string ip){
    return !system(("ping "+ip + " > nul").c_str());
}

void process(int i){

    while(currentProcessedIPIndex<_count){
        cout << '[' << i << "]" << "Pinging " << ipList[currentProcessedIPIndex] << '\n';

        while(1){
            int temp=ping(ipList[currentProcessedIPIndex]);

            if(temp){
                pingableIPs.push_back(ipList[currentProcessedIPIndex]);

                break;
            }
            else{
                unPingableIPs.push_back(ipList[currentProcessedIPIndex]);

                break;
            }
        }

        ++currentProcessedIPIndex;
    }

    

    // if(atomic_is_lock_free(&currentProcessedIPIndex)){
    //     currentProcessedIPIndex=i;

    //     while(currentProcessedIPIndex.load()<(i+num)){
    //         cout << "Pinging " << ipList[currentProcessedIPIndex.load()] << '\n';

    //         if(ping(ipList[currentProcessedIPIndex.load()])){
    //             pingableIPs.push_back(ipList[currentProcessedIPIndex.load()]);
    //         }
    //         else{
    //             unPingableIPs.push_back(ipList[currentProcessedIPIndex.load()]);
    //         }

    //         currentProcessedIPIndex+=1;
    //     }
    // }

    
    // int tmp=i+num;

    // while(i++<tmp){
    //     cout << "Pinging " << ipList[i] << '\n';

    //     if(ping(ipList[i])){
    //         pingableIPs.push_back(ipList[i]);
    //     }
    //     else{
    //         unPingableIPs.push_back(ipList[i]);
    //     }
    // }

    // int tmp=i+num;

    // while(i++<tmp){
    //     cout << "Pinging " << ipList[i] << '\n';

    //     if(ping(ipList[i])){
    //         pingableIPs.push_back(ipList[i]);
    //     }
    //     else{
    //         unPingableIPs.push_back(ipList[i]);
    //     }

    //     ++_count;
    // }
}

void initThreadList(int threadNums){
    int ipNumsEachThread=ipList.size()/threadNums;
    int remainingIPs=ipList.size()%threadNums;
    int i=0;

    while(threadNums--){
        //index.push_back(i*ipNumsEachThread);
        threadList.push_back(thread(process, i++/*, index[i], ipNumsEachThread*/));
        //++i;
    }
    // index.push_back(i*ipNumsEachThread);
    // threadList.push_back(thread(process/*, index[i], ipNumsEachThread+remainingIPs*/));

    

    // while(threadNums-->1){
    //     threadList.push_back(thread(process, i, ipNumsEachThread, threadNums));
    //     i+=ipNumsEachThread;
    //     atomic_fetch_add(&_count, 1);
    // }

    // threadList.push_back(thread(process, i, ipNumsEachThread+remainderIPs, threadNums));

    //cout << threadList.size() << '\n';
}

void output(double executionTime, int ipNums, int threadNums){
    cout << "Amount of IP: " << ipNums << '\n';
    cout << "Amount of Thread: " << threadNums << '\n';

    cout << "Pingable IPs: " << '\n';
    for(string ip : pingableIPs){
        cout << "[OK!] " << ip << '\n'; 
    }

    cout << "Unpingable IPs: " << '\n';
    for(string ip : unPingableIPs){
        cout << "[FAILED!] " << ip << '\n'; 
    }

    cout << "Execution time: " << setprecision(5) << fixed << executionTime << '\n';
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(NULL); cout.tie(NULL);

    int ipNums, threadNums;

    input(ipNums, threadNums);

    initIPList(ipNums);

    clock_t start = clock();

    initThreadList(threadNums);

    // for(auto &th : threadList){
    //     th.join();
    // }

    for(int i=0; i<threadList.size(); ++i){
        threadList[i].join();
    }

    cout << pingableIPs.size() << '\n';
    output((double)(clock() - start)/CLOCKS_PER_SEC, ipNums, threadNums);

    return 0;
}