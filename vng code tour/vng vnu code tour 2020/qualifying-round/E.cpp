#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a, int i, int j){
    int ans=0;
    int _min=1e9, _max=-1;

    for(int k=i; k<=j; ++k){
        _min=min(a[k], _min);
        _max=max(a[k], _max);
    }

    return _max-_min;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    vector<int> arr;
    int tmp, tmp2;

    cin >> n >> q;
    while(n--){
        cin >> tmp;
        arr.push_back(tmp); 
    }
    while(q--){
        cin >> tmp >> tmp2;
        cout << solve(arr, tmp-1, tmp2-1) << '\n';
    }

    return 0;
}