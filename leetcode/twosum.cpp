#include <bits/stdc++.h>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> t;
    vector<int> ans;
        
    for(int i=0; i<nums.size(); ++i){
        t.insert({nums[i], i});
    }
        
    for(int i=0; i<nums.size(); ++i){
        int tmp=target-nums[i];
        map<int, int>::iterator it=t.find(tmp);
            
        if(it!=t.end()){
            ans.push_back(i);
            ans.push_back(it->second);
                       
            return ans;
        }
    }
}

int main(){
    int t;
    vector<int> ans=twoSum(ans, t);
    vector<int> ans=twoSum(ans, t);

    return 0;
}