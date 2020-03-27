#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>>& ma, int m, int n, int o){
    int ans=0;

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(i-o+1>=0 && j-o+1>=0 && !ma[i][j]){
                bool t=1;

                for(int k=i; k>=i-o+1; --k){
                    for(int l=j; l>=j-o+1; --l){
                        if(ma[k][l]){
                            t=0; 

                            break;
                        }
                    }
                    if(!t){
                        break;
                    }
                }
                ans+=t;
                //cout << ans << '\n';
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int s;
    
    cin >> s;
    while(s--){
        int m, n, k, tmp;
        vector<vector<int>> ma;

        cin >> m >> n >> k;
        ma.resize(m);
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                cin >> tmp;
                ma[i].push_back(tmp);
            }
        }

        cout << solve(ma, m, n, k) << '\n';
    }

    return 0;
}