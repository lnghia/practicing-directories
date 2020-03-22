#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k; string s;
	cin >> n >> k >> s;
	int a[k]={};
	int count=0, max=999999;
	for(int i=0; i<s.length(); ++i){
		++a[s[i]-65];
	}
	for(int i=0; i<k; ++i){
		if(a[i]==0){
			cout << 0;
			return 0;
		}
	}
	sort(a, a+k);
	cout << a[0]*k; 
	return 0;
}