#include<bits/stdc++.h>

using namespace std;

int main(){
    int i;
    cin >> i;
    i-=i & (-i);
    cout << i << endl;
    i+=i & (-i);
    cout << i;
    return 0;
}
