#include<bits/stdc++.h>

using namespace std;

void solve(string a, string b){
    int i=0, j=a.length()-1;
    int ans=0;
    if(a[(a.length()-1)/2]!=b[(a.length()-1)/2]){
        //cout << a[(a.length()-1)/2];
        cout << -1 << '\n';
        return;
    }

    while(i!=j){
        if(a[i]!=b[i] && a[j]!=b[j]){
            if(a[i]==b[j] && a[j]==b[i]){
                ++ans;
            }
            else{
                cout << a[i] << b[i] << a[j] << b[j] << '\n';
                cout << -1 << '\n';
                return;
            }
        }
        ++i;
        --j;
    }
    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}
