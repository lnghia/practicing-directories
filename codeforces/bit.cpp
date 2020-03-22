#include<bits/stdc++.h>

using namespace std;

void update(int l, int r, int fen[], int a[]){
    for(int i=l; i<=r; i+=i&(-i)){
        fen[i]+=a[l];
        int t=i &-i;
         cout << t << " " << i << " " << fen[i] << endl;

    }
}

int sum(int l, int fen[]){
    int ans=0;
    for(int i=l; i; i-=i&(-i)){
        ans+=fen[i];

    }
    return ans;
}

int main(){
    int n; cin >> n;
    int a[n+1];
    int fen[n+1]={0};
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    int l;
    //cin >> l;
    for (int i=1; i<=n; ++i) update(i, n, fen, a);
    //for(int i=1; i<n+1; ++i) cout << fen[i] << endl;
    //int answer=sum(l, fen);
    //cout << answer;
    return 0;
}
