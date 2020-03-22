#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution {
public:
    queue<pair<pair<int, int>, int>> q;
    int m, n;
    
    void islandBorder(vector<vector<int>> &a, pair<int, int> t){
        queue<pair<int, int>> temp;
        int t1[]={0, 0, 1, -1};
        int t2[]={1, -1, 0, 0};
        
        temp.push(t);
        while(!temp.empty()){
            pair<int, int> tmp=temp.front();
            
            temp.pop();
            for(int i=0; i<4; ++i){
                int x=tmp.first+t1[i];
                int y=tmp.second+t2[i];
                
                if((x>=0 && x<m) && (y>=0 && y<n)){
                    if(a[x][y]==1){
                        a[x][y]=2;
                        temp.push({x, y});
                    }
                    else if(!a[x][y]){
                        a[x][y]=3;
                        q.push({{x, y}, 1});
                    }
                }
            }
        }
    }
    
    int bfs(vector<vector<int>> &a){
        int d1[]={0, 0, 1, -1}, d2[]={1, -1, 0, 0};
        
        while(!q.empty()){
            pair<pair<int, int>, int> tmp=q.front();
            
            q.pop();
            for(int i=0; i<4; ++i){
                int x=tmp.first.first+d1[i], y=tmp.first.second+d2[i];
                
                if(x>=0 && x<m && y>=0 && y<n){
                    if(a[x][y]==1){
                        return tmp.second;
                    }
                    else if(!a[x][y]){
                        q.push({{x, y}, tmp.second+1});
                        a[x][y]=3;
                    }
                }
            }
        }
        
        return 1;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        bool flag=0;    
    
        m=A.size(), n=(m)?A[0].size():0;
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(A[i][j]){
                    A[i][j]=2;
                    islandBorder(A, {i, j});
                    flag=1;
                    
                    break;
                }
            }
            
            if(flag){
                break;
            }
        }

        return bfs(A);
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