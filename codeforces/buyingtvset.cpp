#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b, x, y;

	cin >> a >> b >> x >> y;
	long long t=__gcd(x, y);
	x/=t; y/=t;
	long long i=2, ans=0;
	ans=min(a/x, b/y);
	cout << ans;

	return 0;
}