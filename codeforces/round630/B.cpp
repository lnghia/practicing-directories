#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, tmp;

    cin >> t;
    while(t--){
        vector<int> a, k;
        int l=2;
        int temp, count=0;

        cin >> tmp;
        k.resize(1001, 1);
        for(int i=0; i<tmp; ++i){
            cin >> temp;
            a.push_back(temp);
        }

        for(int i=0; i<tmp; ++i){
            for(int j=0; j<tmp; ++j){
                if(__gcd(a[i], a[j])==1){
                    if(k[a[i]]==k[a[j]]){
                        k[a[j]]=l++;
                        ++count;
                    }
                }
            }
        }
        cout << count+(tmp-count>0) << '\n';
        for(int i=0; i<tmp; ++i){
            cout << k[a[i]] << ' ';
        }
        cout << '\n';
    }
    cout << __gcd(323, 437) << ' ' << __gcd(323, 391) << '\n';

    return 0;
}