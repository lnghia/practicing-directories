/*
 * =====================================================================================
 *
 *       Filename:  count-and-say.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/27/20 14:43:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   
 *
 ===================================================================================
 */
#include <stdlib.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

string countAndSay(int n){
    int count=0, i=0, tmp;
    string temp="1", ans="1";

    if(n==1){
        return "1";
    }

    while(n-->1){
        i=0; 
        temp=ans;
        ans="";
        while(i<temp.length()){
            char t=temp[i];

            count=0;
            while(i<temp.length() && temp[i]==t){
                ++i; ++count;
            }
            ans+=to_string(count);
            ans+=t;
        }
    }

    return ans;
}

int main(){
    int n, i=1;
    string sampleAns, ans;
    ifstream inp("input.txt");
    
    while(inp >> n){
        inp >> sampleAns;
        ans=countAndSay(n);
        if(sampleAns==ans){
            cout << "Test " << i++ << ": " << ans << " \033[1;32mPassed!\033[0m\n";   
        }
        else{
            cout << "Test " << i++ << ": " << ans << " \033[1;32mFailed!\033[0m\n";
        }
    }
    
    return 0;
}
