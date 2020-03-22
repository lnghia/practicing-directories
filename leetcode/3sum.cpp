#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; ++i){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1, end=nums.size()-1, t1=nums[start], t2=nums[end];

            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];

                if(!sum){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(nums[start]==t1){
                        ++start;
                    }
                    while(nums[end]==t2){
                        --end;
                    }
                    t1=nums[start]; t2=nums[end];
                }
                else if(sum>0){
                    while(nums[end]==t2){
                        --end;
                    }
                    t2=nums[end];
                }
                else{
                    while(nums[start]==t1){
                        ++start;
                    }
                    t1=nums[start];
                }
            }
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    int n, tmp;
    vector<int> t;
    vector<vector<int>> ans;

    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        t.push_back(tmp);
    }

    ans=sol.threeSum(t);

    for(int i=0; i<ans.size(); ++i){
        for(int j=0; j<3; ++j){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}