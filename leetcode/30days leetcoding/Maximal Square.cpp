class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        vector<vector<int>> dp(matrix.size());
        
        if(matrix.empty()) return 0;
        if(matrix.size()==1 && matrix[0].size()==1) return (matrix[0][0]=='1');
        
        for(int i=0; i<matrix[0].size(); ++i){
            dp[0].push_back(matrix[0][i]-'0');
            ans=max(ans, dp[0][i]);
        }
        for(int i=1; i<matrix.size(); ++i){
            dp[i].push_back(matrix[i][0]-'0');
            ans=max(ans, dp[i][0]);
        }
        
        for(int i=1; i<matrix.size(); ++i){
            for(int j=1; j<matrix[i].size(); ++j){
                if(matrix[i][j]=='1'){
                    if(dp[i-1][j]==dp[i][j-1] && dp[i][j-1] && !dp[i-dp[i][j-1]][j-dp[i][j-1]] ){
                        dp[i].push_back(dp[i][j-1]);
                    }
                    else{
                        dp[i].push_back(min(dp[i-1][j], dp[i][j-1])+1);
                    }
                }
                else{
                    dp[i].push_back(0);
                }
                ans=max(ans, dp[i][j]);
            }
        }

        return ans*ans;
    }
};