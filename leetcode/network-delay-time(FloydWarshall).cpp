class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    void floyd(vector<vector<int>>& graph, vector<vector<int>>& dist, vector<vector<int>>& path, int N){
        for(int k=0; k<N; ++k){
            for(int u=0; u<N; ++u){
                for(int v=0; v<N; ++v){
                    if(dist[u][v]>dist[u][k]+dist[k][v]){
                        dist[u][v]=dist[u][k]+dist[k][v];
                        path[u][v]=path[k][v];
                    }
                }
            }
        }
    }
    
    int calDelayTime(vector<vector<int>>& dist, int k, int N){
        int ans=0;
        
        for(int i=0; i<N; ++i){
            if(dist[k][i]==1e9){
                return -1;
            }
            ans=max(ans, dist[k][i]);
        }
        
        return ans;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> graph, path, dist;
        int ans=0;
        
        graph.resize(N, vector<int>(N, 1e9)); 
        path.resize(N, vector<int>(N, -1)); 
        dist.resize(N, vector<int>(N, 1e9));
        for(int i=0; i<N; ++i){
            graph[i][i]=dist[i][i]=0;    
        }
        
        for(int i=0; i<times.size(); ++i){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int w=times[i][2];
            
            if(graph[u][v]>w){
                graph[u][v]=w;
                dist[u][v]=w;
                path[u][v]=u;
            }
        }
        
        floyd(graph, dist, path, N);
        
        return calDelayTime(dist, K-1, N);
    }
};