#include <bits/stdc++.h>

using namespace std;

int pow(int a, int n){
    if(n==0){
        return 1;
    }

    int temp=pow(a, n/2);
    int ans=temp*temp;

    return ans*=(n%2)?a:1;
}

int main(){
    cout << pow(2, 16) << '\n';

    return 0;
}