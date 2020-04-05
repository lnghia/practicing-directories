class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    bool dfs(vector<unordered_set<int>>& g, vector<int>& arr, int start){
        stack<int> s;
        int n=arr.size();
        vector<bool> vs(n, 0);

        s.push(start);
        vs[start]=1;
        while(!s.empty()){
            int curr=s.top(); s.pop();
            int v1=curr+arr[curr];
            int v2=curr-arr[curr];
            
            if(v1<n){
                if(!arr[v1]){
                    return 1;
                }
                if(!vs[v1]){
                    s.push(v1);
                    vs[v1]=1;
                }
            }
            if(v2>=0){
                if(!arr[v2]){
                    return 1;
                }
                if(!vs[v2]){
                    s.push(v2);
                    vs[v2]=1;
                }
            }
        }

        return 0;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<unordered_set<int>> graph;
        
        if(!arr[start]){
            return 1;
        }

        return dfs(graph, arr, start);
    }
};