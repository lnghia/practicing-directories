#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<time.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include<utility>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <string.h>

using namespace std;

bool Base_trans(int B, int x, int xB[]) {
    int i = 0;
    while(x) {
        xB[i] = x % 10;
        x /= 10;
        if(xB[i++] >= B)
            return 0;
    }
    return 1;
}
void show(int xB[]) {
    for(int i = 0; i < 20; ++i) {
        cout << xB[i] << ' ';
    }
    cout << endl;
}
void Base_cal(int B, int xB[], int yB[], int xyB[]) {
    for(int i = 0; i < 15; ++i) {
        for(int j = 0; j < 15; ++j) {
            xyB[i + j] += xB[i] * yB[j];
        }
    }
    for(int i = 0; i < 29; ++i) {
        xyB[i + 1] += xyB[i] / B;
        xyB[i] %= B;
    }
}
bool ok(int a, int b, int c, int B) {
    int aB[30] = {}, bB[30] = {}, cB[30] = {}, abB[30] = {};
    if(!Base_trans(B, a, aB))
        return 0;
    if(!Base_trans(B, b, bB))
        return 0;
    if(!Base_trans(B, c, cB))
        return 0;
    Base_cal(B, aB, bB, abB);
    for(int j = 0; j < 30; ++j) {
        //cout << abB[j] << ' ' << tmp[j] << ' ' << B << endl;
        if(abB[j] != cB[j])
            return 0;
    }
    return 1;
}
int solve(int a, int b, int c) {
    //int a, b, c;
    //cin >> a >> b >> c;
    for(int i = 2; i < 17; ++i) {
        if(ok(a, b, c, i)) {
            return i;
        }
    }
    return -1;
}

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
    for(int i=0; i<a.length(); ++i){
        for(int j=0; j<b.length(); ++j){
            c[i+j]+=(b[i]-'0')*(a[j]-'0');
            index=(index<(i+j))?(i+j):index;
        }
    }
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
    int a, b, c, count=0;
    for(int q=1; q<=100; ++q){
            for(int w=1; w<=100; ++w){
                    for(int e=1; e<=100; ++e){
    string z, x, y, tmp;
    a=q; b=w; c=e;
    x=to_string(a);
    y=to_string(b);
    z=to_string(c);
    x=reverse(x);
    y=reverse(y);
    int i=2, te=-1;
    while(i<=16){
        while(check(x, y, z, i)==0 && i<=16){
            ++i;
        }
        tmp=n(x, y, i);
        if(tmp==z){
            te=i;
            break;
        }
        ++i;
    }
    int test=solve(a, b, c);
    if(test!=te){
        cout << a << ' ' << b << ' ' << c << ' ' << te << ' ' << test << '\n';
        return 0;
    }
    }}}
    return 0;
}
