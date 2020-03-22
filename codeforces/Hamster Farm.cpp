#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin >> n >> k;
    long long a[k];
    long long rs[k];
    long long t;
    for(int i=0; i<k; ++i){
        cin >> a[i];
        t=n/a[i];
        rs[i]=t*a[i];
    }
    long long max=-1;
    int rs1;
    for(int i=0; i<k; ++i){
        if(max<rs[i]){
            max=rs[i];
            rs1=i;
        }
    }
    cout << rs1+1 << " " << n/a[rs1];
    return 0;
}
