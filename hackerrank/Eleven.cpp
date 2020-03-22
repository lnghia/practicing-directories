#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;++i)
#define per(i,a,b) for(int i=a;i>b;--i)
using namespace std;

int main(){
    int n;cin>>n;
    bool a[5000]={};
    int tmp1=1,tmp2=1;
    a[1]=true;a[2]=true;
    while(tmp1<=n){
        tmp1+=tmp2;
        a[tmp1]=true;
        tmp2=tmp1-tmp2;
    }
    string rs;
    rep(i,1,n+1)rs+=a[i]?'O':'o';
    cout<<rs;
    return 0;
}
