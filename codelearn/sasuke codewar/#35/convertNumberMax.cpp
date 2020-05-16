#include <bits/stdc++.h>

using namespace std;

long long convertNumberMax(long long n)
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    long long tmp=n, rs=0;
    int _max=0, ind, len, diff;
    bool isChanged=0;

    while(tmp){
        _max=max(_max, (int)(tmp%10));
        tmp/=10;
    }

    tmp=n;
    int i=0;
    while(tmp){
        if(tmp%10!=_max){
            ind=i;
            diff=_max-(tmp%10);
        }
        ++i;
        tmp/=10;
    }

    return n+(long long)(pow(10, ind)+0.5)*(1LL*diff);
}

int main(){
    long long n;

    cin >> n;
    cout << convertNumberMax(n) << '\n';

    return 0;
}