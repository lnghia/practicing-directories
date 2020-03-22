#include<bits/stdc++.h>
#define per(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[5]={1, 5, 10, 20, 100};
    int ans=0, t;
    per(i, 4, 0){
        if(n>=a[i]){
            t=n/a[i];
            ans+=t;
            n-=t*a[i];
        }
        if(n<=0) break;
    }
    cout << ans;
    return 0;
}
