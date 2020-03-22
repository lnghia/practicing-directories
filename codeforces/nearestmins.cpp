#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, d=0, ans, min=999999999, t=0, min1=999999999;
	cin >> n;
	long long a[100000];
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (min>a[i]) min=a[i];
	}
	for (int i=0; i<n; ++i) {
		if (a[i]==min) {
			for (int j=i+1; j<n; ++j) {
				++d;
				if (a[j]==min) {
					if (min1>d) min1=d;
					i=j-1;
					d=0;
					break;
				}
			}
		}
	}
	cout << min1;
	return 0;
}
