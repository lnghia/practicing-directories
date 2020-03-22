#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    n-=2;
    int a[3];
    a[0]=1; a[1]=1;
    if(n%3==0){
        --n;
        ++a[0];
    }
    a[2]=n;
    cout << a[0] << ' ' << a[1] << ' ' << a[2];
    return 0;
}
