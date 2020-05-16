#include <bits/stdc++.h>

using namespace std;

#define ll long long

long long maxNumber(int a, int b)
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    if(a<b){
        int tmp=a;
        a=b;
        b=tmp;
    }

    long long rs=0;
    int len1=to_string(a).length(), len2=to_string(b).length();
    int tmp1=len1-1, tmp2=len2-1;
    int i=0, j=0;
    int fiD1, fiD2, t1, t2;

    while(i<len1 && j<len2){
        t1=(int)(pow(10, tmp1)+0.5);
        t2=(int)(pow(10, tmp2)+0.5);
        fiD1=a/t1;
        fiD2=b/t2;
        if(fiD1>fiD2){
            rs=rs*(ll)10+(ll)fiD1;
            ++i;
            a-=fiD1*t1;
            --tmp1;
        }
        else{
            rs=rs*(ll)10+(ll)fiD2;
            ++j;
            b-=fiD2*t2;
            --tmp2;
        }
    }
    while(i++<len1){
        t1=(int)(pow(10, tmp1--)+0.5);
        fiD1=a/t1;
        rs=rs*(ll)10+(ll)fiD1;
        a-=fiD1*t1;
    }
    while(j++<len2){
        t2=(int)(pow(10, tmp2--)+0.5);
        fiD2=b/t2;
        rs=rs*(ll)10+(ll)fiD2;
        b-=fiD2*t2;
    }

    return rs;
}

int main(){
    int a, b;

    cin >> a >> b;
    cout << maxNumber(a, b) << '\n';

    return 0;
}