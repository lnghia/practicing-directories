#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    vector<int> a, b;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    for(int i=0; i<m; ++i)
        cin >> b[i];
    int j=0, ans=0;
    for(int i=0; i<n; ++i){
        if(a[i]<b[j]){
            ++ans;
            ++j;
        }
        if(j==m) break;
    }
    cout << ans;
    return 0;
}
