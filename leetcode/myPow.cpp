#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double mPow(double x, int n){
        if(!n){
            return 1;
        }
        
        double tmp=mPow(x, n/2);
        tmp*=tmp;
        tmp*=(n%2)?x:1;
        
        return tmp;
    }
    
    double myPow(double x, int n) {
        double ans=mPow(x, n);
        
        return (n>=-1)?ans:(1/ans);
   }
};

int main(){
    Solution sol;
    int a, n;

    cin >> a >> n;
    cout << sol.myPow(a, n) << '\n';

    return 0;
}
