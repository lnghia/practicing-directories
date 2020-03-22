#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define per(i, b, a) for (int i=b; i>a; --i)
#define ll long long

using namespace std;

int main(){
	ll p, y; cin >> p >> y;
	ll ans=-1, count=0;
	per(i, y, p){
	    count=0;
        rep(j, 2, sqrt(i)) if (i%j==0) ++count;
        if (count==0) { ans=i; break; }
	}
	cout << ans;
	return 0;
}
