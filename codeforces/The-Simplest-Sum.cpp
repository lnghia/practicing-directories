#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;++i)
#define per(i,a,b) for(int i=a;i>b;--i)
using namespace std;
int ForMod=1000000007;

int _pow(int a,int b){
    int rs=1;
    rep(i,0,b)rs*=a;
    return rs;
}
int func1(int a,int b){
    int tmp=(pow(a,b)-1)/(a-1)*a;
    return ((tmp-b)/(a-1))%ForMod;
}
int func2(int a,int b){
    cout<<a<<" "<<b<<" "<<pow(a,b)<<'\n';
    int tmp=pow(a,b);
    cout<<tmp<<" "<<pow(a,b)<<'\n';
    return (tmp/(a-1))%ForMod;
}
int func(int a,int b){
    int i=1,rs=0,prv=0,tmp=func2(a,1);
    while(tmp<b+1){
        rs+=func1(a,i-1)*(tmp-prv);
        rs=rs%ForMod;
        prv=tmp;
        tmp=func2(a,++i);
    }
    rs+=(b+1-prv)*func1(a,i-1);
    return rs%ForMod;
}
void solve(){
    int a,b,c;cin>>a>>b>>c;
    cout<<func(a,c)-func(a,b-1)<<'\n';
    return;
}
void example(){
    int a,b;cin>>a>>b;
    cout<<func2(a,b)<<'\n';
    //cout<<func(a,b)<<'\n';
    return;
}
int main(){
    example();
    //int t;cin>>t;
    //while(t-->0)solve();
    return 0;
}
