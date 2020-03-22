#include<bits/stdc++.h>
#include <vector>
#include <thread>

using namespace std;

// vector<string> ipList;
// vector<vector<string> > pingableIPs, unpingableIPs;
// vector<thread> threadList;
//vector<int> index;

// void input(int &ipNums, int &threadNums){
//     cout << "Enter the number of IP: ";
//     cin >> ipNums;
    
//     cout << "Enter the number of thread: ";
//     cin >> threadNums;

//     pingableIPs.resize(threadNums);
//     unpingableIPs.resize(threadNums);
// }

// void initIPList(int ipNums){
//     vector<string> ips;
//     int i=1;
//     string ip;

//     while(ipNums--){
//         cout << "Enter IP number " << i++ << ": ";
//         cin >> ip;

//         ipList.push_back(ip);
//     }
// }

// bool ping(string ip){
//     return !system(("ping -c 4 "+ip + " > nul").c_str());
// }

// void process(int thread, int ipNumsEachThread){
//     for(int i=thread*ipNumsEachThread; i<(thread+1)*ipNumsEachThread; ++i){
//         cout << '[' << thread << "] " << "Pinging " << ipList[i] << '\n';

//         if(ping(ipList[i])){
//             pingableIPs[thread].push_back(ipList[i]);
//         }
//         else{
//             unpingableIPs[thread].push_back(ipList[i]);
//         }
//     }
// }

// void initThreadList(int threadNums){
//     int ipNumsEachThread=ipList.size()/threadNums;
//     int remainingIPs=ipList.size()%threadNums;
//     int i=0;

//     while(threadNums-->1){
//         threadList.push_back(thread(process, i++, ipNumsEachThread));
//     }

//     threadList.push_back(thread(process, i, ipNumsEachThread+remainingIPs));
// }

// void output(double executionTime, int ipNums, int threadNums){
//     cout << "Amount of IP: " << ipNums << '\n';
//     cout << "Amount of Thread: " << threadNums << '\n';

//     cout << "Pingable IPs: " << '\n';
//     for(int i=0; i<pingableIPs.size(); ++i){
//         for(int j=0; j<pingableIPs[i].size(); ++j){
//             cout << "[OK!] " << pingableIPs[i][j] << '\n';
//         } 
//     }

//     cout << "Unpingable IPs: " << '\n';
//     for(int i=0; i<unpingableIPs.size(); ++i){
//         for(int j=0; j<unpingableIPs[i].size(); ++j){
//             cout << "[OK!] " << unpingableIPs[i][j] << '\n';
//         } 
//     }

//     cout << "Execution time: " << setprecision(5) << fixed << executionTime << '\n';
// }

int main(){
    //int ipNums, threadNums;

    //input(ipNums, threadNums);

    //initIPList(ipNums);
    string ip="www.google.com";

    clock_t start = clock();

    //ping("www.google.com");
    cout << "p\n";
    system(("ping "+ip).c_str());
    //initThreadList(threadNums);

    // for(int i=0; i<threadList.size(); ++i){
    //     threadList[i].join();
    // }

    //cout << pingableIPs.size() << '\n';
    cout << fixed << setprecision(3) << (double)(clock() - start)/CLOCKS_PER_SEC;
    // output((double)(clock() - start)/CLOCKS_PER_SEC, ipNums, threadNums);

    return 0;
}