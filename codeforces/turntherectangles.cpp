#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int w[n], h[n];
	string ans="YES";
	int t;
	for(int i=0; i<n; ++i){
		cin >> w[i] >> h[i];
		if(i==0)
		    t=max(w[0], h[0]);
		if(w[i]>h[i]) swap(w[i], h[i]);
		if(t>=h[i] && i>0){
		    t=h[i];
		}
		else if(t>=w[i] && i>0){
		    t=w[i];
		}
		else if(i>0){
		    ans="NO";
		    break;
		}
	}
	cout << ans;
	return 0;
}