#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k, tmp;
    vector<ll> q; 
    int ans=-1;

    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        q.push_back(tmp);
    }

    for(int i=0; i<n; ++i){
        ll sum=q[i];
        for(int j=i+1; j<n; ++j){
            if(sum==k){
                ans=max(ans, j-i+1);
            }
            sum+=q[j]
        }
    }
    cout <<

    return 0;
}