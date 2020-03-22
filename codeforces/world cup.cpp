#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    int i=0, ans, t=0;
    while(1){
        if(a[i]<=0) break;
        else a[i]+=t;
        if(i==n-1){
            i=0;
            ++t;
        }
        else{
            ++i;
            ++t;
        }
        if(i==0) a[n-1]-=t;
        else a[i-1]-=t;
        a[i]-=t;
        cout << i << " " << a[0] << " " << a[1] << " " << t << endl;
    }
    ans=i+1;
    cout << ans;
    return 0;
}
