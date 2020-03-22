#include<bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int sum=0, sum1=0, ans=0;
    rep(i, 0, n){
        cin >> a[i];
        sum+=a[i];
    }
    int k=sum/2;
    rep(i, 0, n){
        sum1+=a[i];
        ++ans;
        if(sum1>=k){
            break;
        }
    }
    cout << ans+1;
    return 0;
}
