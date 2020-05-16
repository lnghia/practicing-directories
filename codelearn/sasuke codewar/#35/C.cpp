#include <bits/stdc++.h>

using namespace std;

string sum(int a, int b, int n){
    long long rs=1;
    long long c=1;
    long long tmp=(long long)(pow(10, n)+0.5f);

    while(b--){
        c=(c*a)%tmp;
        rs=(rs+c)%tmp;
    }

    return to_string(rs);
}

string nLastChar(int a, int b, int n)
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    long long s=1;
    string ans="", temp=sum(a, b, n);
    int len=temp.length();

    cout << temp << '\n';

    if((len-n)<0){
        for(int i=0; i<(n-len); ++i){
            ans+='0';
        }
        ans+=temp;
    }
    else{
        for(int i=len-n; i<len; ++i){
            ans+=temp[i];
        }
    }

    return ans;
}

int main(){
    int a, b, n;

    cin >> a >> b >> n;
    cout << nLastChar(a, b, n) << '\n';

    return 0;
}
