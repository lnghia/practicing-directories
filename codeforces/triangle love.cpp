#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<=b; ++i)

using namespace std;

int main(){
	int n, t=0; cin >> n;
	int a[n+1];
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) if (a[a[a[i]]]==i){ t=1; break; }
       // int pos1=a[i];
       // int pos2=a[pos1];
       // int pos3=a[pos2];
       // if (i==pos3){ t=1; break; }
	if (t==1) cout << "yes";
	else cout << "no";
	return 0;
}
