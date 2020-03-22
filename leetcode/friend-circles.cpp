#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void makeSet(vector<int>& parents, vector<int>& ranks, int m){
    for(int i=0; i<m; ++i){
        parents.push_back(i);
        ranks.push_back(0);
    }
}

int findParent(vector<int>& parents, int u){
    if(parents[u]!=u){
        parents[u]=findParent(parents, parents[u]);
    }

    return parents[u];
}

void unite(vector<int>& parents, vector<int>& ranks, int u, int v){
    int up=findParent(parents, u);
    int vp=findParent(parents, v);

    if(up==vp){
        return;
    }
    if(ranks[up]>ranks[vp]){
        parents[vp]=up;
    }
    else if(ranks[up]<ranks[vp]){
        parents[up]=vp;
    }
    else{
        parents[vp]=up;
        ++ranks[up];
    }
}

int findCircleNum(vector<vector<int>>& M) {
    int m=M.size(), ans=0;
    vector<int> parents, ranks;

    if(!m){
        return 0;
    }        

    makeSet(parents, ranks, m);
    for(int i=0; i<m; ++i){
        for(int j=0; j<m; ++j){
            if(M[i][j]){
                unite(parents, ranks, i, j);
            }
        }
    }
    for(int i=0; i<m; ++i){
        ans+=(parents[i]==i);
    }

    return ans;
}

int main(){
    int m, n, sampleAns, ans, tmp, t=1;
    ifstream inp("input.txt");

    while(inp >> m >> n >> sampleAns){
        vector<vector<int>> graph(m);

        for(int i=0; i<m; ++i){
            for(int j=0; j<m; ++j){
                inp >> tmp;
                graph[i].push_back(tmp);
            }
        }
        ans=findCircleNum(graph);

        if(ans==sampleAns){
            cout << "Test " << t++ << ": " << ans << "\033[1;32m Passed!\033[0m\n";
        }
        else{
            cout << "Test " << t++ << ": " << ans << "\033[1;31m Failed!\033[0m\n";
        }
    }
    inp.close();

    return 0;
}