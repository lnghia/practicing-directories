class Solution {
public:
    vector<vector<int>> ans={};
    vector<int> tmp={};
    
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    void findCombination(vector<int>& candidates, vector<int>& combination, int sum, int target, int index){
        for(int i=index; i<candidates.size(); ++i){
            sum+=candidates[i];
            combination.push_back(candidates[i]);
            if(sum>target){
                combination.pop_back();
                
                return;
            }
            if(sum==target){
                ans.push_back(combination);
                combination.pop_back();
                
                return;
            }
            findCombination(candidates, combination, sum, target, i);
            sum-=combination.back();
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(!candidates.size()){
            return {};
        }
        
        sort(candidates.begin(), candidates.end());
        findCombination(candidates, tmp, 0, target, 0);
        
        return ans;
    }
};