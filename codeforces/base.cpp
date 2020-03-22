#include<bits/stdc++.h>
#include <vector>
#include <string.h>

using namespace std;

/*void convert(int a, int t, string &ans){
    if(!a) return;
    char temp[]={'A', 'B', 'C', 'D', 'E', 'F'};
    int tmp=a%t;
    if(tmp>=10){
        ans+=temp[tmp-10];
    }
    else{
        string tmp1=to_string(tmp);
        ans+=tmp1;
    }
    a/=t;
    convert(a, t, ans);
}*/

int check(string a, string b, string c, int l){
    for(int i=0; i<a.length(); ++i)
        if(a[i]-'0'>=l)
            return 0;
    for(int i=0; i<b.length(); ++i)
        if(b[i]-'0'>=l)
            return 0;
    for(int i=0; i<c.length(); ++i)
        if(c[i]-'0'>=l)
            return 0;
    return 1;
}

string reverse(string t){
    string ans="";
    for(int i=t.length()-1; i>=0; --i){
        ans+=t[i];
    }
    return ans;
}

string n(string a, string b, int h){
    string ans="", tmp, t1;
    int t=0, temp, pos=1;
    int c[100]={}, index=-1;
    for(int i=0; i<b.length(); ++i){
        for(int j=0; j<a.length(); ++j){
            c[i+j]+=(b[i]-'0')*(a[j]-'0');
            index=(index<(i+j))?(i+j):index;
        }
    }
    cout << c[0] << ' ' << c[1] << ' ' << c[2] <<'\n';
    for(int i=0; i<=index; ++i){
        c[i]+=t;
        t=0;
        if(c[i]>=h){
            t=c[i];
            c[i]%=h;
            t/=h;
        }
    }
    if(t){
        c[++index]=t;
    }
    cout << c[0] << ' ' << c[1] << ' ' << c[2] << '\n';
    for(int i=index ; i>=0 ; --i){
        if(c[i]>=10){
            return "false";
        }
        ans+=to_string(c[i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b, c;
    string z, x, y, tmp;
    cin >> a >> b >> c;

    x=to_string(a);
    y=to_string(b);
    z=to_string(c);
    x=reverse(x);
    y=reverse(y);
    int i=2;
    while(i<=16){
        while(check(x, y, z, i)==0 && i<=16){
            ++i;
        }
        tmp=n(x, y, i);
        if(tmp==z){
            cout << i;
            return 0;
        }
        ++i;
    }
    cout << -1;
    return 0;
}
