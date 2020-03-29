#include <bits/stdc++.h>

using namespace std;

class DSU{
public:
    vector<int> parents, ranks;

    DSU(){}
    DSU(int n){
        ranks.resize(n+1, 0);
        for(int i=0; i<=n; ++i){
            parents.push_back(i);
        }
    }

    int findSet(int u){
        if(u!=parents[u]){
            parents[u]=findSet(parents[u]);
        }

        return parents[u];
    }

    bool unite(int u, int v){
        int up=findSet(u);
        int vp=findSet(v);

        if(up==vp){
            return 0;
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

        return 1;
    }
};

void swap(int& a, int& b){
    int tmp=a;
    a=b;
    b=tmp;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    DSU dsu;
    int n=0;

    for(auto& e : edges){
        n=max(n, e[0]);
        n=max(n, e[1]);
    }    
    dsu=DSU(n);

    for(auto& e : edges){
        if(!dsu.unite(e[0], e[1])){
            if(e[0]>e[1]){
                swap(e[0], e[1]);
            }

            return {e[0], e[1]};
        }
    }

    return {};
}

int main(){
    vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,4},{1,5}};

    vector<int> ans=findRedundantConnection(edges);
    cout << ans[0] << ' ' << ans[1] << '\n';

    return 0;
}
