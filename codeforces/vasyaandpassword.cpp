#include<bits/stdc++.h>

using namespace std;

int max(int a, int b, int c){
    if(a<b) a=b;
    if(a<c) a=c;
    return a;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        string s;
        int k[3]={};
        cin >> s;
        int a[s.length()]={};
        for(int i=0; i<s.length(); ++i){
            if(s[i]>='a' && s[i]<='z'){
                ++k[0];
            }
            if(s[i]>='A' && s[i]<='Z'){
                ++k[1];
                a[i]=1;
            }
            if(s[i]>='0' && s[i]<='9'){
                ++k[2];
                a[i]=2;
            }
        }
        if(k[0]==0){
            int temp=max(k[1],k[2]), tmp;
            if(k[1]==temp) tmp=1;
            else tmp=2;
            for(int i=0; i<s.length(); ++i){
                if(a[i]==tmp){
                    s[i]='a';
                    a[i]=0;
                    break;
                }
            }
        }
        if(k[1]==0){
            int temp=max(k[0],k[2]), tmp;
            if(k[0]==temp) tmp=0;
            else tmp=2;
            for(int i=0; i<s.length(); ++i){
                if(a[i]==tmp){
                    s[i]='A';
                    a[i]=1;
                    break;
                }
            }
        }
        if(k[2]==0){
            int temp=max(k[0],k[1]), tmp;
            if(k[0]==temp) tmp=0;
            else tmp=1;
            for(int i=0; i<s.length(); ++i){
                if(a[i]==tmp){
                    s[i]='1';
                    a[i]=2;
                    break;
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}
