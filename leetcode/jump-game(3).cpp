#include <bits/stdc++.h>

using namespace std;

class DSU{
public:
    vector<int> parents, ranks;

    DSU(){}
    DSU(int n){
        ranks.resize(n, 0);
        for(int i=0; i<n; ++i){
            parents.push_back(i);
        }
    }

    int findSet(int u){
        if(parents[u]!=u){
            parents[u]=findSet(parents[u]);
        }

        return parents[u];
    }

    void unite(int u, int v){
        int up=findSet(u);
        int vp=findSet(v);

        if(up==vp){
            return;
        }
        if(ranks[up]>ranks[vp]){
            parents[vp]=up;
        }
        else if(ranks[vp]>ranks[up]){
            parents[up]=vp;
        } 
        else{
            parents[vp]=up;
            ++ranks[up];
        }
    }
};

bool dfs(vector<vector<int>>& g, vector<int>& arr, int start){
    stack<int> s;
    int n=arr.size();
    vector<bool> vs(n, 0);

    s.push(start);
    vs[start]=1;
    while(!s.empty()){
        int curr=s.top(); s.pop();

        for(auto& v : g[curr]){
            if(!arr[v]){
                return 1;
            }
            if(!vs[v]){
                s.push(v);
                vs[v]=1;
            }
        }
    }

    return 0;
}

void initGraph(vector<vector<int>>& gr, vector<int>& arr){
    int n=arr.size();

    gr.resize(n);
    for(int i=0; i<n; ++i){
        if(i-arr[i]>=0){
            gr[i].push_back(i-arr[i]);
            gr[i-arr[i]].push_back(i);
        }
        if(i+arr[i]<n){
            gr[i].push_back(arr[i]+i);
            gr[arr[i]+i].push_back(i);
        }
    }
}

bool canReach(vector<int>& arr, int start){
    int n=arr.size();
    vector<vector<int>> graph;

    initGraph(graph, arr);

    return dfs(graph, arr, start);
}

int main(){
    vector<int> arr={4,2,3,0,3,1,2};
    int start=0;

    cout << canReach(arr, start) << '\n';

    return 0;
}