#include <bits/stdc++.h>

using namespace std;

int ans=0;
int maxVal=0, bagCapacity, stuffNum;
vector<vector<int>> rs;
vector<int> carriedThings;

bool isValid(int currTotalWeight, int itemWeight){
    return (currTotalWeight+itemWeight)<=bagCapacity;
}

void backtracking(vector<pair<int, int>>& stuffList, int currTotalWeight, int currTotalVal, int index){
    for(int i=index+1; i<stuffNum; ++i){
        if(isValid(currTotalWeight, stuffList[i].first)){
            currTotalWeight+=stuffList[i].first;
            currTotalVal+=stuffList[i].second;
            carriedThings.push_back(i);
        }
        else{
            continue;
        }

        if(maxVal<currTotalVal){
            maxVal=currTotalVal;
            rs.push_back(carriedThings);
        }
        if(currTotalWeight==bagCapacity){
            currTotalVal-=stuffList[i].second;
            currTotalWeight-=stuffList[i].first;
            carriedThings.pop_back();

            continue;
        }
        
        backtracking(stuffList, currTotalWeight, currTotalVal, i);
        currTotalWeight-=stuffList[i].first;
        currTotalVal-=stuffList[i].second;
        carriedThings.pop_back();
    }
}

void printCarriedThings(){
    int tmp=rs.size()-1;

    for(int i=0; i<rs[tmp].size(); ++i){
        cout << rs[tmp][i] << ' ';
    }
}

int main(){
    vector<pair<int, int>> stuffList={ {5, 10},{4, 40},{6, 30},{3, 50} };
    bagCapacity=10; stuffNum=stuffList.size();

    backtracking(stuffList, 0, 0, -1);
    cout << maxVal << '\n';
    printCarriedThings();

    return 0;
}

