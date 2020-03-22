#include<iostream>

using namespace std;

int main(){
    long long x;
    cin >> x;
    if(x==0) cout << 0;
    else if(x%2!=0) cout << (x+1)/2;
    else cout << x+1;
    return 0;
}