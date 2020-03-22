#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; ++i)

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, 0, n){
        cin >> a[i];
    }
    int i=0, j=n-1, ans=0, t1=0, t2=0;
    while(i<j){
        if(a[i]<=k){
            ++ans;
            ++i;
            t1=1;
        }
        else t1=0;
        if(a[j]<=k){
            ++ans;
            --j;
            t2=1;
        }
        else t2=0;
        if(t2==t1 && t1==0){
            cout << ans;
            return 0;
        }
    }
    if(i==j && a[i]<=k) ++ans;
    cout << ans;
    return 0;
}
