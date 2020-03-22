#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a, b, c, k;
	int ans=-1, l=0, t;
	string t1; 
	for(int i=0; i<n; ++i){
		cin >> t >> t1;
		if(t1=="A"){
			a.push_back(t);
		}
		if(t1=="B"){
			b.push_back(t);
		}
		if(t1=="C"){
			c.push_back(t);
		}
		if(t1=="ABC"){
			k.push_back(t);
		}
	}
	if(a.size()==0 || b.size()==0 || c.size()==0){
		l=1;
	}
	if(k.size()==0 && l==1){
		cout << -1;
		return 0;
	}
	if(l==1){
		cout << k[0];
		return 0;
	}
	if(k.size()==0){
		cout << a[0]+b[0]+c[0];
		return 0;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	sort(k.begin(), k.end());
	if((a[0]+b[0]+c[0])<k[0]){
		cout << a[0]+b[0]+c[0];
	}
	else cout << k[0];
	return 0;
}