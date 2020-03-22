#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<bool>> checked;
    queue<pair<pair<int, int>, int>> q;
    vector<vector<pair<int, int>>> path;
    vector<vector<bool>> visited;

    void traceBack(vector<vector<int>> &a, vector<vector<pair<int, int>>> &path, const pair<int, int> &t){
        int x=t.first, y=t.second, tmp;

        while(1){
            if(path[x][y].first==-1){
                return;
            }
            tmp=path[x][y].second;
            x=path[x][y].first;
            y=tmp;
            if(a[x][y]!=1){
                checked[x][y]=1;
            }
        }
    }

    int BFS(vector<vector<int>> &a, const pair<int, int> &t){
        int d1[]={0, 0, 1, -1}, d2[]={1, -1, 0, 0};

        q=queue<pair<pair<int, int>, int>>();

        for(int i=0; i<a.size(); ++i){
            for(int j=0; j<a[0].size(); ++j){
                visited[i][j]=0;
            }
        }

        for(int i=0; i<a.size(); ++i){
            for(int j=0; j<a[0].size(); ++j){
                path[i][j]={-1, -1};
            }
        }

        q.push({t, 1});
        visited[t.first][t.second]=1;
        while(!q.empty()){
            pair<pair<int, int>, int> tmp=q.front();
                        
            q.pop();
            for(int k=0; k<4; ++k){
                int x=tmp.first.first+d1[k];
                int y=tmp.first.second+d2[k];
                            
                if(x>=0 && x<a.size() && y>=0 && y<a[0].size() && !visited[x][y]){
                    if(a[x][y]==0){
                        q.push({{x, y}, tmp.second+1});
                        visited[x][y]=1;
                        path[x][y]=tmp.first;
                    }
                    else if(a[x][y]==1){
                        path[x][y]=tmp.first;
                        traceBack(a, path, {x, y});

                        return tmp.second;
                    }
                }
            }
        }
            
        return -1; 
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int ans=-1, count=0, count1=0;
       
        if(!grid.size()){
            return -1;
        }

        visited.resize(grid.size());
        for(int i=0; i<grid.size(); ++i){
            visited[i].resize(grid[0].size());
        }

        path.resize(grid.size());
        for(int i=0; i<grid.size(); ++i){
            path[i].resize(grid[0].size());
        }

        checked.resize(grid.size());
        for(int i=0; i<grid.size(); ++i){
            checked[i].resize(grid[0].size(), 0);
        }

        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                count+=!grid[i][j];
                count1+=grid[i][j];
            }
        }

        if(!count || !count1){
            return -1;
        }
        
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                if(!checked[i][j] && grid[i][j]==0){
                    ans=max(ans, BFS(grid, {i, j}));
                }
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

    cout << sol.maxDistance(a) << '\n';

    return 0;
}