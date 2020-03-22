#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n], b[n], c[k];
    int t=0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        b[i]=a[i];
        if(a[i]!=a[i-1] && i>0) t=1;
    }
    if(t==0){
        cout << a[0] << endl;
        int p=n/k;
        for(int i=0; i<k-1; ++i){
            cout << p << " ";
        }
        cout << n-k+1;
        return 0;
    }
    sort(b, b+n);
    int j=k-1;
    int l=n-1;
    while(j>=0){
        c[j]=b[l];
        --j; --l;
    }
    int ans=0;
    for(int i=0; i<k; ++i){
        ans+=c[i];
    }
    cout << ans << endl;
    j=0;
    //if(a[0]!=c[0])
    for(int i=1; i<k; ++i){
        int count=0;
        while(a[j]!=c[i] && j<n){
            ++count;
            ++j;
        }
        cout << count << " ";
        if(j<n && i==k-1){
            cout << n-j;
        }
    }
    return 0;
}
