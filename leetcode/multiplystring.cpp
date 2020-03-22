#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    string multiply(string &num1, string &num2) {
        if(num1[0]==48 || num2[0]==48){
            cout << 1 << '\n';
                
            return 0;
        }
        
        int n1=num1.length(), n2=num2.length(), carry, k=1, tmp;
        string ans="";
        
        if((n1==1 && num1[0]=='1')){
            return num2;
        }
        if(n2==1 && num2[0]=='1'){
            return num1;
        }
        
        for(int i=0; i<=n1+n2; ++i){
            ans+="0";
        }
        k=(n1+n2);
        
        for(int i=n1-1; i>=0; --i){
            int t=k;
            for(int j=n2-1; j>=0; --j){
                int tmp=(num1[i]-48)*(num2[j]-48);
                int temp=tmp+ans[t]-48;
                    
                ans[t]=(temp%10+'0');
                ans[t-1]=(temp/10+ans[t-1]-48+'0');
                --t;
            }
            --k;
        }
        int i=0;
        string rs="";
        
        while(ans[i]=='0'){
            ++i;
        }
        while(i<ans.length()){
            rs+=ans[i++];
        }
        
        return rs;
    }
};

int main(){
    int m, n;
    Solution sol;

    cin >> m >> n;
    cout << sol.multiply(m, n) << '\n';

    return 0;
}