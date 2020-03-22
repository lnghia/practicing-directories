#include <bits/stdc++.h>

using namespace std;

struct Pos{
    int x;
    int step;
    int possibleFarestDes;
    
    Pos(int X, int Step, int P){
        x=X;
        step=Step;
        possibleFarestDes=P;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<Pos> zeroPos, possibleLongestDes;
        vector<int> min;
        int tmp=1e9;
        Pos pre(0, 0, 0), temp(0, 0, 0);
        int des=nums.size()-1;
        
        for(int i=0; i<=des; ++i){
            if(!nums[i]){
                possibleLongestDes.push_back(temp);
                zeroPos.push_back(Pos(i, 0, 0));
                min.push_back(tmp);
                temp.x=temp.step=temp.possibleFarestDes=0;
                tmp=1e9;
            }
            else{
                if((i+nums[i])>temp.possibleFarestDes){
                    temp.x=i;
                    temp.step=nums[i];
                    temp.possibleFarestDes=i+nums[i];
                }
                if(i<tmp){
                    tmp=i;
                }
            }
        }
        
        if(!zeroPos.size()){
            return 1;
        }
        pre.x=0;
        pre.step=nums[0];
        pre.possibleFarestDes=0+nums[0];
        for(int i=0; i<possibleLongestDes.size(); ++i){
            if(i==0 && zeroPos[0].x<possibleLongestDes[0].x){
                return 0;
            }
            if(i<zeroPos.size() && possibleLongestDes[i].x<zeroPos[i].x &&                 possibleLongestDes[i].possibleFarestDes>zeroPos[i].x){
                if(possibleLongestDes[i].possibleFarestDes>pre.possibleFarestDes
                  && pre.possibleFarestDes>=min[i]){
                    pre.x=possibleLongestDes[i].x;
                    pre.step=possibleLongestDes[i].step;
                    pre.possibleFarestDes=possibleLongestDes[i].possibleFarestDes;
                }
            }
            if(pre.possibleFarestDes>=des){
                return 1;
            }
        }
        
        return 0;
    }
};

int main(){
    vector<int> tmp={3,2,1,0,4};
    Solution sol;

    cout << sol.canJump(tmp) << '\n';

    return 0;
}