#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n], min=999999, ans=0;
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i=0; i<n-1; ++i){
		ans+=((a[i+1]-a[i])>1)?((a[i+1]-a[i])-1):0;
	}
	cout << ans;

	return 0;
}