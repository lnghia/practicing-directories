#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    queue<pair<int, int>> islandBorder(vector<vector<int>> &a, pair<int, int> t){
        queue<pair<int, int>> q;
        queue<pair<int, int>> ans;
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
                        ans.push({x, y});
                    }
                }
            }
        }
        
        return ans;
    }
    
    int BFS(vector<vector<int>> &a, pair<int, int> t){
        int m=a.size(), n=(m)?a[0].size():0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited;
        int t1[]={0, 0, 1, -1};
        int t2[]={-1, 1, 0, 0};
        
        visited.resize(m);
        for(int i=0; i<m; ++i){
            visited[i].resize(n, 0);
        }
        
        q.push({t, 1});
        visited[t.first][t.second]=1;
        while(!q.empty()){
            pair<pair<int, int>, int> tmp=q.front();
            
            q.pop();
            for(int i=0; i<4; ++i){
                int x=tmp.first.first+t1[i];
                int y=tmp.first.second+t2[i];
                
                if( (x>=0 && x<m) && (y>=0 && y<n) && !visited[x][y]){
                    if(a[x][y]==1){
                        return tmp.second;
                    }
                    else{
                        q.push({{x, y}, tmp.second+1});
                        visited[x][y]=1;
                    }
                }
            }
        }
        
        return 1;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int m=A.size(), n=(m)?A[0].size():0;
        queue<pair<int, int>> bfs, border;
        int ans=1e9;
        bool flag=0;
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(A[i][j]==1){
                    flag=1;
                    border=islandBorder(A, {i, j});
                    A[i][j]=2;

                    break;
                }
            }
            if(flag){
                break;
            }
        }

        while(!border.empty()){
            pair<int, int> tmp=border.front();
            border.pop();
            ans=min(ans, BFS(A, tmp));
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

