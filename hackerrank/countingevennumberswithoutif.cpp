#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, count=0;
	vector<int> a(n);
	cin >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
		count+=a[i]%2==0;
	}
	cout << count;
	return 0;
}

