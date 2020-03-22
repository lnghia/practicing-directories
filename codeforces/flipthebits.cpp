#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t>0){
		int count=0;
		cin >> n;
		int m=n-1;
		while(n>0){
			count+=((n&1)!=(m&1));
			n/=2;
			m/=2;
			//cout << " m va n" << m << " " << n << endl;
		}
		cout << count << endl;
		--t;
	}
	return 0;
}