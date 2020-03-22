#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
int bagCapacity, stuffNum;

int solve(vector<pair<int, int>>& stuffList){
    for(int item=1; item<=stuffNum; ++item){
        for(int capacity=0; capacity<=bagCapacity; ++capacity){
            if(stuffList[item-1].second>bagCapacity){
                continue;
            }

            int maxValWithoutCurrItem=dp[item-1][capacity];
            int maxValWithCurrItem=0;
            int currWeight=stuffList[item-1].second;

            if(capacity>=currWeight){
                int remainingSlot=capacity-currWeight;

                maxValWithCurrItem=stuffList[item-1].first+dp[item-1][remainingSlot];
            }

            dp[item][capacity]=max(maxValWithoutCurrItem, maxValWithCurrItem);
        }
    }

    return dp[stuffNum][bagCapacity];
}

int main(){
    vector<pair<int, int>> stuffList={ {10, 5},{40, 4},{50, 6},{30, 3} };
    bagCapacity=10; stuffNum=stuffList.size();

    dp.resize(stuffNum+1);
    for(int i=0; i<=stuffNum; ++i){
        dp[i].resize(bagCapacity+1);
    }

    for(int i=0; i<=bagCapacity; ++i){
        dp[0][i]=0;
    }
    for(int i=0; i<=stuffNum; ++i){
        dp[i][0]=0;
    }

    cout << solve(stuffList) << '\n';

    return 0;
}