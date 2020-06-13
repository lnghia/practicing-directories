#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct option{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const{
        return a.second > b.second;
    }
};

int dijk(int s, vector<vector<pair<int, int>>>& g, vector<int>& k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> q;
    vector<int> dist(g.size(), 1e9);
    vector<int> path(g.size());
    int ans=1e9;

    q.push({s, 0});
    dist[s]=0;
    while(!q.empty()){
        pair<int, int> top=q.top();
        q.pop();
        int u=top.first;
        int w=top.second;

        for(int i=0; i<g[u].size(); ++i){
            pair<int, int> nb=g[u][i];
            if(w+nb.second<dist[nb.first]){
                dist[nb.first]=w+nb.second;
                q.push({nb.first, dist[nb.first]});
                path[nb.first]=u;
            }
        }
    }

    for(auto& i : k){
        ans=min(ans, dist[i]);
    }

    return (ans==1e9)?-1:ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    int u, v, w;
    vector<vector<pair<int, int>>> g;
    vector<int> tmp;

    cin >> n >> m;
    g.resize(n+1);
    while(m--){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cin >> k;
    int t;
    while(k--){
        cin >> t;
        tmp.push_back(t); 
    }

    for(int i=1; i<=n; ++i){
        cout << dijk(i, g, tmp) << ' ';
    }

    return 0;
}