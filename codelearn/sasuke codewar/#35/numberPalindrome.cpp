#include <bits/stdc++.h>

using namespace std;

bool numberPalindrome(long long n)
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    n=abs(n);

    if(n<10){
        return true;
    }

    int len, fiDigit, laDigit;

    while(n){
        len=log10(n);
        fiDigit=(n/pow(10, len));
        laDigit=n%10;
        cout << n << ' ' << len << ' ' << fiDigit << ' ' << laDigit << '\n';
        if(fiDigit!=laDigit){
            return false;
        }
        n-=fiDigit*pow(10, len);
        n/=10;
    }

    return true;
}

int main(){
    int tmp;

    cin >> tmp;
    cout << numberPalindrome(tmp) << '\n';

    return 0;
}