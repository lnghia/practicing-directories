class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    int singleNumber(vector<int>& nums) {
        int ans=0;
        
        for(auto& i : nums){
            ans^=i;
        }
        
        return ans;
    }
};