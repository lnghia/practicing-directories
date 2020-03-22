#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    map<string, int> a;
    int p; string name;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> name >> p;
        a[name]=p;
    }
    while(cin>>name){
        if(a[name]){
            cout << name << "=" << a[name] << '\n';
        }
        else cout << "Not found" << '\n';
    }
    return 0;
}