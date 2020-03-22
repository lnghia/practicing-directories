#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int, string> > a(n);
	for(int i=0; i<n; ++i){
		cin >> a[i].first >> a[i].second;
		sort(a[i].second.begin(), a[i].second.end());
	}
	int ans=0, min=9999999, t=0, t1=0;
	string test="A";
	cout << test.find("BC");
	string s="", t2="";
	while(s.length()<3){
		if(t>3){
			cout << -1;
			return 0;
		}
		for(int i=0; i<n; ++i){
			if(a[i].first<min && s.find(a[i].second)==string::npos){
				cout << a[i].first << ' ' << a[i].second << ' ' << s.find(a[i].second) << '\n';
				s.resize(s.length()-t2.length());
				ans-=t1;
				ans+=a[i].first;
				min=a[i].first;
				t1=min;
				s+=a[i].second;
				t2=a[i].second;
			}
		}
		t2="";
		t1=0;
		min=999999;
		++t;
	}
	cout << ans;
	return 0;
}