#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline string myTrim(string &str){
        int i=0;
        string ans="";
        
        while(i<str.length()){
            if(str[i]!=' '){
                ans+=str[i];
            }
            ++i;
        }
        
        return ans;
    }
    
    inline int myAtoi(string &str) {
        long long ans=0;
        bool isNegative;
        string number="";
        
        if(str==""){
            return 0;
        }
        
        str=myTrim(str);
        if(str=="" || ((str[0]<48 || str[0]>57) && str[0]!='-')){
            return 0;
        }
        
        for(char ch : str){
            if(!isNegative){
                isNegative=(ch=='-');
            }
            if(ch>=48 && ch<=57){
                ans=ans*10+(ch-48);
            }
        }
        ans*=(isNegative)?-1:1;
        if(ans<INT_MIN){
            return INT_MIN;
        }
        if(ans>INT_MAX){
            return INT_MAX;
        }
        
        return ans;
    }
};

int main(){
    string str;
    Solution sol;

    getline(cin, str);

    cout << sol.myAtoi(str) << '\n';

    return 0;
}