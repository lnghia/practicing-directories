class Solution {
public:
    bool ans=0;
    int length;
    bool isFirstEleStar;
    char arr[3]={'(', ')', '*'};
    int openParenthesisCount=0, closeParenthesisCount=0, parenNum=0;
    
    void checkEveryCases(string& s, int index){
        int tmp=index;
        int t1=openParenthesisCount, t2=closeParenthesisCount;
        
        if(ans || index==length){
            return;
        }
        
        if(s[index]=='*'){
            for(int i=0; i<3; ++i){
                if(ans){
                    return;
                }
                if(!index){
                    openParenthesisCount=closeParenthesisCount=0;
                }
                if(isFirstEleStar && !index && i==1){
                    continue;   
                }
                openParenthesisCount=t1;
                closeParenthesisCount=t2;
                if(!i){
                    ++openParenthesisCount;
                }
                else if(i==1){
                    ++closeParenthesisCount;
                }
                if(openParenthesisCount>parenNum || closeParenthesisCount>parenNum || closeParenthesisCount>openParenthesisCount){
                    continue;
                }
                if(openParenthesisCount+closeParenthesisCount==2*parenNum){
                    ans=1;
                    
                    return;
                }
                checkEveryCases(s, index+1);
            }    
        }
        else{
            if(s[index]=='('){
                ++openParenthesisCount;
            }
            else{
                ++closeParenthesisCount;
            }
            if(openParenthesisCount>parenNum || closeParenthesisCount>parenNum || closeParenthesisCount>openParenthesisCount){
                return;
            }
            if(openParenthesisCount+closeParenthesisCount==2*parenNum){
                ans=1;
                    
                return;
            }
            checkEveryCases(s, index+1);
        }
    }
    
    bool checkValidString(string& s) {
        length=s.length();
        
        if(!length){
            return 1;
        }
        isFirstEleStar=(s[0]=='*');
        if(s[0]==')' || s[length-1]=='('){
            return 0;
        }
        parenNum=length/2;
        checkEveryCases(s, 0);
        
        return ans;
    }
};