#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> cache;

int solve(map<int, int>& a, int m){
    int ans=0;

    for(auto& n : a){
        int tmp=m-n.first;

        for(int i=1; i<=tmp; ++i){
            if(i==n.first){
                ans+=()
            }
        }
        if(a.find(m-n.first)!=a.end()){
            ans+=(n.second*a[m-n.first]);
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n, tmp;
    map<int, int> arr;

    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        if(arr.find(tmp)!=arr.end()){
            ++arr[tmp];
        }
        else{
            arr[tmp]=1;
        }
    }

    for(auto& n : arr){
        cout << n.first << ' ' << n.second << '\n';
    }

    cout << solve(arr, m);
    
    return 0;
}   