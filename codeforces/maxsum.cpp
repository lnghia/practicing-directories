#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n+1]={}, ans[n+1]={}, t=0;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(a[i-1]>0){
            a[i]+=a[i-1];
            t=1;
        }
    }
    sort(a, a+n+1);
    if(t)
        cout << a[n];
    else cout << a[n-1];
    return 0;
}
