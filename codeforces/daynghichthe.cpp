#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; i+=i&-i)
#define REP(i, a, b) for(int i=a; i<b; ++i)

using namespace std;

void update(int p, int val, int fen[], int n){
    rep(i, p, n+1)
        fen[i]+=val;
}

int main(){
    int n;
    cin >> n;
    int a[n+1];
    int fen[n+1]={0};
    REP(i, 1, n+1) cin >> a[i];
    REP(i, 1, n+1) update(i, a[i], fen, n);
    REP(i, 1, n+1) cout << fen[i] << " ";
    return 0;
}
