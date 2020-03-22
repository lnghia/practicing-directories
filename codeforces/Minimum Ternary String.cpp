#include<bits/stdc++.h>

using namespace std;

void swap(char &m, char &n){
    char t=m;
    m=n;
    n=t;
}

int cmp(string a, string b){
    for(int i=0; i<a.length(); ++i){
        if(a[i]-48<b[i]-48)
            return 1;
    }
    return 0;
}

int main(){
    string s;
    cin >> s;
    string s1=s;
    int l=s.length()-1;
    for(int i=0; i<l; ++i){
        if(s[i]!='2' || s[i+1]!='0'){
            if(s[i]-48>s[i+1]-48)
                swap(s[i], s[i+1]);
        }
    }
    for(int i=l-1; i>0; --i){
        if(s1[i]!='0' || s1[i-1]!='2'){
            if(s1[i]-48<s1[i-1]-48)
                swap(s1[i], s1[i-1]);
        }
    }
    if(cmp(s, s1)==1) cout << s;
    else cout << s1;
    return 0;
}
