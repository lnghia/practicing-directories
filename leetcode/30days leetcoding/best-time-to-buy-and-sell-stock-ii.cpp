class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int n;
    
    int solve(vector<int>& a){
        int profit=0, i=0;
        
        while(i<n-1){
            int j=i;
            
            while(j+1<n && a[j+1]>=a[j]){
                ++j;
            }
            profit+=a[j]-a[i];
            i=j+1;
        }
        
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        if(!n){
            return 0;
        }
        
        return solve(prices);
    }
};