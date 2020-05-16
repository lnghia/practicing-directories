#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> gr;
vector<vector<int>> path;
vector<bool> vs;
int ans=0;

void dfs(int h, int x, int y){
    stack<pair<int, int>> q;
    int i=0;
    int prev=sum;

    if(x+1<h){
        for(int k=0; k<1; ++k){
            sum=prev;
            sum+=gr[x+1][y+k];
            path[]
            if(sum>ans){
                
            }
            dfs()
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h;

    cin >> h;
    gr.resize(h);
    for(int i=0; i<h; ++i){
        int tmp;

        for(int j=0; j<i; ++j){
            cin >> tmp;
            gr[i].push_back(tmp);
        }
    }
    vs.resize(h*2, 0);
    path.resize(h, vector<int>(h, -1));


    return 0;
}