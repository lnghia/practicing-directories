#include <bits/stdc++.h>

using namespace std;

int ans=0;
int maxVal=0, bagCapacity, stuffNum;

void backtracking(vector<pair<int, int>>& stuffList, int currTotalWeight, int currTotalVal, int index){
    for(int i=index+1; i<stuffNum; ++i){
        currTotalWeight+=stuffList[i].first;
        currTotalVal+=stuffList[i].second;

        if(currTotalWeight>bagCapacity){
            currTotalVal-=stuffList[i].second;
            currTotalWeight-=stuffList[i].first;
            maxVal=max(maxVal, currTotalVal);

            continue;
        }
        if(currTotalWeight==bagCapacity){
            maxVal=max(maxVal, currTotalVal);
            currTotalVal-=stuffList[i].second;
            currTotalWeight-=stuffList[i].first;

            continue;
        }
        maxVal=max(maxVal, currTotalVal);

        backtracking(stuffList, currTotalWeight, currTotalVal, i);
        currTotalWeight-=stuffList[i].first;
        currTotalVal-=stuffList[i].second;
        carriedThings.pop_back();
    }
}

int main(){
    vector<pair<int, int>> stuffList={ {5, 10},{4, 40},{6, 30},{3, 50} };
    bagCapacity=10; stuffNum=stuffList.size();

    backtracking(stuffList, 0, 0, -1);

    return 0;
}

