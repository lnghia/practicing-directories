class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    void swap(int& a, int& b){
        int tmp=a;
        a=b;
        b=tmp;
    }
    
    void moveZeroes(vector<int>& nums) {
        int f=0, s=0, n=nums.size();
        
        while(f<n && s<n){
            while(s<n && !nums[s]) ++s;
            if(s<n && nums[s]){
                swap(nums[f++], nums[s++]);   
            }
        }
    }
};