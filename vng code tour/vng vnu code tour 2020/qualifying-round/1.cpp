#include <bits/stdc++.h>

using namespace std;

bool bfs(int u, int v, int n, vector<vector<char>>& ma){
  queue<pair<int, int>> q;
  vector<vector<bool>> visited;
  int d1[]={0, 0, 1, -1}, d2[]={1, -1, 0, 0};
  
  visited.resize(n, vector<bool>(n, 0));
  q.push({u, v});
  visited[u][v]=1;
  while(!q.empty()){
    pair<int, int> curr=q.front(); q.pop();
    
    for(int i=0; i<4; ++i){
      int x=curr.first+d1[i];
      int y=curr.second+d2[i];
      
      if(x<0 || x>=n || y<0 || y>=n){
        continue;
      }
      if(!visited[x][y]){
        if(ma[x][y]=='*'){
          return 1;
        }
        else if(ma[x][y]=='.'){
          q.push({x, y});
          visited[x][y]=1;
        }
      }
    }
  }
  
  return 0;
}

int main(){
  vector<vector<char>> ma;
  int n;
  char tmp;
  
  cin >> n;
  ma.resize(n);
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      cin >> tmp;
      ma[i].push_back(tmp);
    }
  }
  
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      if(ma[i][j]=='*'){
        if(bfs(i, j, n, ma)){
          cout << "YES";
        }
        else{
          cout << "NO";
        }
        
        return 0;
      }
    }
  }
  
  return 0;
}