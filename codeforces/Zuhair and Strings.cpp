#include <bits/stdc++.h>

using namespace std;

bool isvalid(string s){
	for(int i=0; i<s.length()-1; ++i){
		if(s[i+1]!=s[i]){
			return false;
		}
	}

	return true;
}

int solve(int n, int k, string s){
	int t=0, it=0, temp=0, ch=0;
	bool tmp;
	int ans=0;
	vector<string> a;

	while(it<n){
		string j="";
		for(int i=it; i<k+it; ++i){
			j+=s[i];
		}
		if(isvalid(j)){
			a.push_back(j);
		}
		it+=k;
	}
	for(int i=0; i<26; ++i){
		t=0;
		for(int j=0; j<a.size(); ++j){
			if(a[j][0]-'a'==i){
				++t;
			}
		}
		ans=max(ans, t);
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0)
	int n, k;
	string s;

	cin >> n >> k;
	cin >> s;
	cout << solve(n, k, s);

	return 0;
}