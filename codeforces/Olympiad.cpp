#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)

using namespace std;

int main(){
	int n, count=0, t=0; cin >> n;
	int a[n], b[601]={0};
	rep(i, 0, n) { cin >> a[i]; t=a[i]==0?1:0; ++b[a[i]]; }
	rep(i, 0, 601) if (b[i]!=0) ++count;
	if (b[0]==0) cout << count;
	else cout << count-1;
	return 0;
}
