#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> islandBorder(vector<vector<int>> &a, pair<int, int> t){
        queue<pair<int, int>> q;
        vector<pair<int, int>> ans;
        int t1[]={0, 0, 1, -1};
        int t2[]={1, -1, 0, 0};
        int m=a.size(), n=(m)?a[0].size():0;
        
        q.push(t);
        while(!q.empty()){
            pair<int, int> tmp=q.front();
            
            q.pop();
            for(int i=0; i<4; ++i){
                int x=tmp.first+t1[i];
                int y=tmp.second+t2[i];
                
                if((x>=0 && x<m) && (y>=0 && y<n)){
                    if(a[x][y]==1){
                        a[x][y]=2;
                        q.push({x, y});
                    }
                    else if(!a[x][y]){
                        a[x][y]=3;
                        ans.push_back({x, y});
                    }
                }
            }
        }
        
        return ans;
    }
    
    vector<pair<int, int>> findIsland(vector<vector<int>> &a){
        vector<pair<int, int>> q;
        
        for(int i=0; i<a.size(); ++i){
            for(int j=0; j<a[i].size(); ++j){
                if(a[i][j]==1){
                    a[i][j]=2;
                    
                    return islandBorder(a, {i, j});
                }
            }
        }
        
        return q;
    }

    void output(vector<vector<int>> &a){
        for(int i=0; i<a.size(); ++i){
            for(int j=0; j<a[i].size(); ++j){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int m=A.size(), n=(m)?A[0].size():0;
        queue<pair<int, int>> bfs;
        vector<pair<int, int>> border1, border2;
        int ans=1e9, tmp;
        
        border1=findIsland(A);
        border2=findIsland(A);

        cout << '\n';
        output(A);
        cout << "-----\n";
        
        for(int i=0; i<border1.size(); ++i){
            for(int j=0; j<border2.size(); ++j){
                int t=(int)sqrt(pow(border2[j].first-border1[i].first, 2)+pow(border2[j].second-border1[i].second, 2));
                cout << border1[i].first << ' ' << border1[i].second << ' ' << border2[j].first << ' ' << border2[j].second << ' ' << t << '\n';
                ans=min(ans, t);
            }
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    int m, n, tmp;
    vector<vector<int>> a;

    cin >> m >> n;
    a.resize(m);
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }

    cout << sol.shortestBridge(a) << '\n';

    return 0;
}