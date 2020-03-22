#include <bits/stdc++.h>
#include <queue>
#include <fstream>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    queue<pair<int, int>> q;
    vector<vector<bool>> visited;
    int m=matrix.size(), n=(m)?matrix[0].size():0;
    int d1[]={0, 0, 1, -1}, d2[]={1, -1, 0, 0};

    visited.resize(m);
    for(int i=0; i<m; ++i){
        visited[i].resize(n, 0);
    }

    if(matrix[0][0]==target){
        return 1;
    }

    q.push({0, 0});
    visited[0][0]=1;
    while(!q.empty()){
        pair<int, int> tmp=q.front();

        q.pop();
        if(matrix[tmp.first][tmp.second]>target){
            continue;
        }
        for(int i=0; i<4; ++i){
            int x=tmp.first+d1[i];
            int y=tmp.second+d2[i];
            
            if(x>=0 && x<m && y>=0 && y<n && !visited[x][y]){
                if(matrix[x][y]==target){
                    return 1;
                }
                q.push({x, y});
                visited[x][y]=1;
            }
        }
    }

    return 0;
}

int main(){
    int m, n, tmp, sampleAns, ans, target, i=1;
    ifstream inp("input.txt");

    while(inp >> m >> n >> target >> sampleAns){
        vector<vector<int>> matrix(m);

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                inp >> tmp;
                matrix[i].push_back(tmp);
            }
        }
        ans=searchMatrix(matrix, target);
        if(ans==sampleAns){
            cout << "Test " << i++ << ": " << ans << "\033[1;32m Passed!\033[0m\n";
        }
        else{
            cout << "Test " << i++ << ": " << ans << "\033[1;31m Failed!\033[0m\n";
        }
    }
    inp.close();

    return 0;
}
