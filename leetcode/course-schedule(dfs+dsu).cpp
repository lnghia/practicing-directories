class DSU{
public:
    vector<int> parents, ranks;
    
    DSU(){}
    DSU(int n){
        parents.resize(n); ranks.resize(n, 1);
        for(int i=0; i<n; ++i){
            parents[i]=i;
        }
    }
    
    int findSet(int u){
        if(parents[u]!=u)
            parents[u]=findSet(parents[u]);
        
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
        else if(ranks[up]<ranks[vp]){
            parents[up]=vp;
        }
        else{
            parents[vp]=up;
            ++ranks[up];
        }
    }
};

class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    DSU dsu;
    bool tmp=1;
 
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    void initGraph(vector<vector<int>>& prerequisites, int numCourses){
        graph.resize(numCourses); 
        visited.resize(numCourses, 0);
        for(int i=0; i<prerequisites.size(); ++i){
            int course=prerequisites[i][0];
            int prerequisite=prerequisites[i][1];
            
            graph[prerequisite].push_back(course);
            dsu.unite(prerequisite, course);
        }
    }
    
    void dfs(int u){
        visited[u]=1;
        for(int i=0; i<graph[u].size(); ++i){
            int v=graph[u][i];
            
            if(!visited[v]){
                dfs(v);   
            }
            else{
                tmp=0; 
            }
            
            if(!tmp){
                return;
            }
        }
        visited[u]=0;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count1=0, count2=0;
        dsu=DSU(numCourses);
        
        initGraph(prerequisites, numCourses);
        for(int i=0; i<numCourses; ++i){
            if(dsu.parents[i]==i){
                dfs(i);
            }
            if(!tmp){
                return tmp;
            }
        }
        
        return tmp; 
    }
};