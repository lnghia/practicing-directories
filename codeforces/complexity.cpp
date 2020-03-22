#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define per(i, a, b) for (int i=a; i>b; --i)
#define ll long long
#define vi vector<int>


using namespace std;



int main(){
	string s;
	int a[26]={};
	int t=0;
	int ans=0;

	cin >> s;
	rep(i, 0, s.length()){
		++a[s[i]-97];
	}
	rep(i, 0, 26){
		t+=a[i]>0?1:0;
		a[i]=a[i]>0?a[i]:999;
	}
	sort(a, a+26);
	int i=0;
	while(t>2 && i<=25){
		--t;
		ans+=a[i];
		++i;
	}
	cout << ans;

	return 0;
}
