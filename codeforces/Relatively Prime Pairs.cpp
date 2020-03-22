#include<bits/stdc++.h>

using namespace std;

int main(){
    long long r, l;
    cin >> l >> r;
    cout << "YES" << '\n';
    long long i=l;
    while(i<r){
        cout << i << ' ' << i+1 << '\n';
        i+=2;
    }
    return 0;
}
