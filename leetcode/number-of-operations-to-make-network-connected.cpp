#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int pcNum, connectionNum;

int findParent(vector<int>& parent, int u){
    if(parent[u]!=u){
        parent[u]=findParent(parent, parent[u]);
    }

    return parent[u];
}

void unite(vector<int>& parent, vector<int>& rank, int v1, int v2){
    int p1=findParent(parent, v1);
    int p2=findParent(parent, v2);

    if(p1==p2){
        return;
    }
    if(rank[p1]>rank[p2]){
        parent[p2]=p1;
    }
    else if(rank[p1]<rank[p2]){
        parent[p1]=p2;
    }
    else{
        parent[p1]=p2;
        ++rank[p2];
    }
}

void makeSet(vector<int>& parent, vector<int>& rank){
    for(int i=0; i<pcNum; ++i){
        parent[i]=i;
        rank[i]=0;
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> parent(n);
    vector<int> rank(n);
    int ans=0;

    if(connections.size()<n-1){
        return -1;
    }

    pcNum=n; connectionNum=connections.size();
    makeSet(parent, rank);
    for(int i=0; i<connections.size(); ++i){
        unite(parent, rank, connections[i][0], connections[i][1]);
    }
    for(int i=0; i<n; ++i){
        ans+=(parent[i]==i);
    }

    return ans-1;    
}

int main(){
    int v1, v2, ans, sampleAns, i=1;
    ifstream inp("input.txt");

    while(inp >> pcNum >> connectionNum >> sampleAns){
        vector<vector<int>> graph;
        
        while(connectionNum--){
            inp >> v1 >> v2;
            graph.push_back({v1, v2});
        }
        ans=makeConnected(pcNum, graph);
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
