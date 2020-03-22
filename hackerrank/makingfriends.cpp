#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	int n;
	int ans=-1;
	while(t>0){
		ans=-1;
		cin >> n;
		int k=n;
		n=2*k+1;
		int h[n];
		for(int i=1; i<n; ++i){
			cin >> h[i];
		}
		for(int i=1; i<n; ++i){
			ans=(h[i]+h[2*k-i+1])>ans?(h[i]+h[2*k-i+1]):ans;
		}
		cout << ans << endl;
		--t;
	}
	return 0;
}		