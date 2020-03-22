#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; ++i)

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s+='*';
    int count=0;
    int i=0;
    int count1=0;
    while(i<n){
        if(s[i]=='.'){
            ++count1;
        }
        ++i;
    }
    i=0;
      int ans=0;
      int count2=0;
      int bool1=0;
    if(a==0 || b==0){
        rep(i, 0, n+1){
            if(s[i]=='.'){
                ++count2;
            }

            if(s[i]=='*'){
                ans+=(count2+1)/2;

                count2=0;
            }
        }
        bool1=1;
    }
    else {
            while(i<n+1 && a>0){
        if(s[i]=='.'){
            ++count;
            i+=2;
            --a;
        }
        else ++i;
    }

    int t=count1-count;
    if(t>=b) ans=b+count;
    if(t<b) ans=t+count;
    }
    if(bool1==1){
        if(a!=0) ans=min(a, ans);
        else ans=min(b, ans);
    }
    cout << ans;
    return 0;
}
