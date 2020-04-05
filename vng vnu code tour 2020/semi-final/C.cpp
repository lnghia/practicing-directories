#include <bits/stdc++.h>

using namespace std;

#define ll long long
int si;
ll temp=0;
int tmp1=0;

void solve(vector<ll>& prizes, ll k, int in){
    ll prev=temp;

    if(tmp1){
        return;
    }
    for(int i=in; i<si; ++i){
        temp=prev;
        temp=temp^prizes[i];
        if(temp==k){
            tmp1=1;

            return;
        }
        if(temp>k){
            return;
        }
        solve(prizes, k, in+1);
        if(tmp1){
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k, tmp;
    vector<ll> prizes;

    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        prizes.push_back(tmp);
    }
    sort(prizes.begin(), prizes.end());
    si=prizes.size();

    solve(prizes, k, 0);

    if(tmp1==1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}