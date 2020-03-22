#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int a[3]={0};
    int pos[3]={-1};
    int t, t1, t2;
    for (int i=0; i<s.length(); ++i){
        if(s[i]=='a'){
            t=i;
            ++i; a[0]=1;
            while(s[i]=='a'){
                ++i;
                ++a[0];
                pos[0]=i;
            }
        }
        if(s[i]=='b'){
            t1=i;
            ++i; a[1]=1;
            while(s[i]=='b'){
                ++i;
                ++a[1];
                pos[1]=i;
            }
        }
        if(s[i]=='c'){
            t2=i;
            ++i; a[2]=1;
            while(s[i]=='c'){
                ++i;
                ++a[2];
                pos[2]=i;
            }
        }
        if(t<t1 && t1<t2)
            if(a[0]==a[2] || a[1]==a[2]){
                cout << "YES";
                return 0;
            }
    }
    cout << "NO";
    return 0;
}
