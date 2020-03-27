class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    int expandFromCenter(string &s, int i, int j){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            --i;
            ++j;
        }
        --j; ++i;
        
        return j-i+1;
    }
    
    string longestPalindrome(string s) {
        int n=s.length();
        int start=0, end=0;
        
        if(!n){
            return "";
        }
        
        for(int i=0; i<n; ++i){
            int l1=expandFromCenter(s, i, i);
            int l2=expandFromCenter(s, i, i+1);
            int l=max(l1, l2);
            
            if(l>(end-start+1)){
                start=i-(l-1)/2;
                end=i+l/2;
            }
        }
        
        return s.substr(start, (end-start+1));
    }
};