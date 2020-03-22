#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b, m, min;
	vector<int> k;
	cin >> n >> a >> b;
	if (a<b) m=a;
	else m=b; 
	int t=(a+b)/n;
	min=t;
	if (m>t) 
		while (m>0) {
			m=m-t;
			if (min>m && m>0) min=m;
		}	
	else min=m;
	cout << min;
	return 0;
}
