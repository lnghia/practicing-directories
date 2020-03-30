class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
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

    bool initGraph(vector<vector<int>>& gr, vector<int>& arr){
        int n=arr.size();
        int count=0;

        gr.resize(n);
        for(int i=0; i<n; ++i){
            count+=(!arr[i]);
            if(i-arr[i]>=0){
                gr[i].push_back(i-arr[i]);
                gr[i-arr[i]].push_back(i);
            }
            if(i+arr[i]<n){
                gr[i].push_back(arr[i]+i);
                gr[arr[i]+i].push_back(i);
            }
        }
        
        return count;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<vector<int>> graph;
        
        if(!arr[start]){
            return 1;
        }

        if(!initGraph(graph, arr)){
            return 0;
        }

        return dfs(graph, arr, start);
    }
};
