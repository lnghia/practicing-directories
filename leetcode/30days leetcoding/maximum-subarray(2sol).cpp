#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& arr){
    int prev=arr[0], prevC=0, ans=0;

    for(auto& x : arr){
        if(x==prev){
            ++prevC;
        }
        else{
            if(x==prev+1){
                ans+=prevC;
            }
            prevC=1;
            prev=x;
        }
    }
}

int main(){
    vector<int> arr={}    

    return 0;
}
