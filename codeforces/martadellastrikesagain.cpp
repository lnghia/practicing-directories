#include <bits/stdc++.h>

using namespace std;

int main(){
	long long t, r, r1;

	cin >> t;
	while(t--){
		cin >> r >> r1;
		cout << ((r*r*3.14)<=(2*r1*r1*3.14))+1 << '\n';
	}
	return 0;
}