#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline string Palindrome(string &s, int h, int t){
        string ans="";
        int i=h, j=t;

        while(i<j){
            if(s[i]!=s[j]){
                return "";
            }

            ans+=s[i];
            ++i;
            --j;
        }

        while(i<=t){
            ans+=s[i++];
        }
        
        return ans;
    }
    
    string longestPalindrome(string s) {
        string tmp, ans="";
        int maxLength=0;
        
        if(s.length()<=1){
            return s;
        }
        
        for(int i=0; i<s.length()-1; ++i){
            for(int j=i+1; j<s.length(); ++j){
                tmp=Palindrome(s, i, j);
                
                if(tmp!="" && maxLength<tmp.length()){
                    ans=tmp;
                    maxLength=ans.length();
                }
            }
        }        
        if(ans==""){
            ans+=s[0];
        }
        
        return ans;
    }
};

int main(){
    string s;
    Solution sol;

    cin >> s;
    cout << sol.longestPalindrome(s) << '\n';

    return 0;
}