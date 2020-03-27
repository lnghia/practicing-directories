class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        queue<int> q;
        vector<set<int>> graph;
        vector<int> ans={};
        
        graph.resize(n);
        for(int i=0; i<edges.size(); ++i){
            int u=edges[i][0];
            int v=edges[i][1];
            
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        for(int i=0; i<n; ++i){
            if(graph[i].size()==1){
                q.push(i);
            }
        }
        
        while(n>2){
            unordered_set<int> tmp;
            
            n-=q.size();
            
            while(!q.empty()){
                int curr=q.front(); q.pop();
                
                for(auto nxt : graph[curr]){
                    graph[nxt].erase(curr);
                    tmp.insert(nxt);
                }
            }
            
            for(auto curr : tmp){
                if(graph[curr].size()<=1){
                    q.push(curr);
                }
            }
        }
        
        while(!q.empty()){
            int curr=q.front(); q.pop();
            
            if(graph[curr].size()<=1){
                ans.push_back(curr);
            }
        }
        
        return (ans.size())?ans:vector<int>{0};
    }
};