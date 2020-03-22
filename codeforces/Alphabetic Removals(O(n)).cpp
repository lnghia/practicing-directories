#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector <int>> pos;
    pos.resize(26);
    for(int i=0; i<n; ++i){
        pos[s[i]-97].push_back(i);
    }
    int i=0, j=0;
    while(k>0 && i<26){
        j=0;
        while(j<pos[i].size() && k>0){
            s[pos[i][j]]='_';
            ++j;
            --k;
        }
        ++i;
    }
    for(int i=0; i<n; ++i){
        if(s[i]!='_') cout << s[i];
    }
    return 0;
}
