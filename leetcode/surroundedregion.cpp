#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<bool>> checked;
    queue<pair<int, int>> q;
    int m, n;
    
    void bfs(vector<vector<char>> &board, int d1[], int d2[]){
        while(!q.empty()){
            pair<int, int> tmp=q.front();
            
            q.pop();
            for(int i=0; i<4; ++i){
                int x=tmp.first+d1[i], y=tmp.second+d2[i];
                
                if(x>=0 && x<m && y>=0 && y<n && !checked[x][y]){
                    if(board[x][y]=='O'){
                        q.push({x, y});
                        checked[x][y]=1;
                    }
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int d1[]={0, 0, 1, -1}, d2[]={1, -1, 0, 0};
        
        m=board.size(); n=(m)?board[0].size():0;
        
        checked.resize(m);
        for(int i=0; i<m; ++i){
            checked[i].resize(n);
        }
        
        for(int i=0; i<m; ++i){
            if(board[i][0]=='O'){
                checked[i][0]=1;
                q.push({i, 0});
            }
            if(board[i][n-1]=='O'){
                checked[i][n-1]=1;
                q.push({i, n-1});
            }
        }
        
        for(int i=0; i<n; ++i){
            if(board[0][i]=='O'){
                checked[0][i]=1;
                q.push({0, i});
            }
            if(board[m-1][i]=='O'){
                checked[m-1][i]=1;
                q.push({m-1, i});
            }
        }
        
        bfs(board, d1, d2);
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j]=='O' && !checked[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};

int main(){
    Solution sol;
    int m, n, tmp;
    vector<vector<char>> a;

    cin >> m >> n;
    a.resize(m);
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }

    sol.solve(a);

    return 0;
}