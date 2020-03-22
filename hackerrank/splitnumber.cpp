#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t>0){
		int x, n;
		cin >> x >> n;
		vector<int> a;
		if(x<n){
			cout << -1 << endl;
		}
		else if(n==1){
			cout << x << endl;
		}
		else{
			while(n>0){
				int k=x/n;
				x-=k;
				--n;
				a.push_back(k);
			}
			sort(a.begin(), a.end());
			for(int i=0; i<a.size(); ++i){
				cout << a[i] << " ";
			}
		}
		--t;
	}
	return 0;
}