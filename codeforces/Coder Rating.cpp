#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; ++i)
#define Rep(i, a, b) for(int i=a; i<=b; i+=i&-i)
#define Per(i, a, b) for(int i=a; i>=b; i-=i&-i)

using namespace std;

void update(int p, int fen[]){
    Rep(i, p, 200000){
        ++fen[i];
    }
}

int sum(int k, int fen[]){
    int rs=0;
    Per(i, k-1, 1)
        rs+=fen[i];
    return rs;
}

int main(){
    int n; cin >> n;
    int a[n+1]={0}, h[n+1]={0}, t[n+1]={0};
    rep(i, 1, n+1){
        cin >> a[i] >> h[i];
        t[i]=a[i]+h[i];
    }
    int fen[200001]={0};
    rep(i, 1, n+1){
        update(t[i], fen);
    }
    cout << endl;
    //rep(i, 1, n+1) cout << fen[i] << endl;
    rep(i, 1, n+1){
        int rs=sum(t[i], fen);
        cout << rs << endl;
    }
    return 0;
}

