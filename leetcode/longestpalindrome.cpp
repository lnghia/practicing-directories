#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    inline int longestPalindrome(string &s) {
        int ans=0, max=0;
        int count[58]={};
        bool isOdd=0;
        
        for(int i=0; i<s.length(); ++i){
            ++count[s[i]-'A'];
        }
        
        for(int i : count){
            if(!isOdd && i%2){
                isOdd=1;
            }
            ans+=i/2*2;
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    string s;

    cin >> s;
    cout << sol.longestPalindrome(s) << '\n';

    return 0;
}