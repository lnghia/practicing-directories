#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	++n;
	int a[n], m[100001]={};
	int k[100001]={};
	for(int i=1; i<n; ++i){
		cin >> a[i];
		++m[a[i]];
	}
	for(int i=1; i<n; ++i){
		if(m[a[i]]>1){
			cout << 0;
			return 0;
		}
	}
	int t, count=0;
	for(int i=1; i<n; ++i){
		t=(a[i]&x);
		if(m[t]>0 && t!=a[i]){
			cout << 1;
			return 0;
		}
	}
	for(int i=1; i<n; ++i){
		t=(a[i]&x);
		if(k[t]>0){
			cout << 2;
			return 0;
		}
		++k[t];
	}
	cout << -1;
	return 0;
}