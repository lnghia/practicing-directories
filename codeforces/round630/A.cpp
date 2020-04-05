#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, tmp;

    cin >> t;
    while(t--){
        vector<int> a;
        int k[1000]={}, l=2;
        int temp, count=0;

        cin >> tmp;
        for(int i=0; i<tmp; ++i){
            cin >> temp;
            a.push_back(temp);
        }

        for(int i=0; i<tmp; ++i){
            for(int j=0; j<tmp; ++j){
                count+=__gcd(a[i], a[j])==1;
                k[a[i]]=1;
                k[a[j]]=1;
            }
        }
        cout << count+1 << '\n';
        for(int i=0; i<tmp; ++i){
            if(k[i]){
                cout << l++ << ' ';
            }
            else{
                cout << 1 << ' ';
            }
        }
    }

    return 0;
}