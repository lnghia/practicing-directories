struct option{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const{
        return a.second>b.second;
    }  
};

class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    vector<int> dist;
    
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    void init(vector<vector<int>>& times, int n){
        graph.resize(n);
        dist.resize(n, 1e9);
        
        for(auto& e : times){
            graph[e[0]-1].push_back({e[1]-1, e[2]});
        }
    }
    
    void dijkstra(int k){
        priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
        
        pq.push({k, 0});
        dist[k]=0;
        while(!pq.empty()){
            pair<int, int> curr=pq.top(); pq.pop();
            int u=curr.first;
            int w=curr.second;
            
            for(auto& neighbor : graph[u]){
                if(w+neighbor.second<dist[neighbor.first]){
                    dist[neighbor.first]=w+neighbor.second;
                    pq.push({neighbor.first, dist[neighbor.first]});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int ans=0;
        
        init(times, N);
        
        dijkstra(K-1);
        
        for(auto& i : dist){
            if(i==1e9){
                return -1;
            }
            ans=max(ans, i);
        }
        
        return ans;
    }
};