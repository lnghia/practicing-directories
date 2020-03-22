#include<bits/stdc++.h>
#define vi vector<int>
#define rep(i, a, b) for(int i=0; i<a; ++i)
#define per(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

int main(){
    int n, a, b, c, t;
    cin >> n >> a >> b >> c >> t;
    int k[n];
    for(int i=0; i<n; ++i){
        cin >> k[i];
    }
    int rs;
    if(c-b>0){
        rs=c*n+b*n;
    }
    else rs=a*n;
    cout << rs;
    return 0;
}
