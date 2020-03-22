#include <bits/stdc++.h>

using namespace std;

bool isvalid(string s, int k){
	if(s.length()!=k){
		return false;
	}
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
	vector<vector<string> > a;

	while(it<n){
		string l="";
		vector<string> tmp;
		int i=it;
		while(i<n){
			l="";
			for(int j=i; j<k+i; ++j){
				l+=s[j];
			}
			if(isvalid(l, k)){
				tmp.push_back(l);
			}
			i+=k;
		}
		++it;
		/*for(int o=0; o<tmp.size(); ++o){
			cout << o << ' ';
		}
		cout << '\n';*/
		a.push_back(tmp);
	}

	/*for(int i=0; i<a.size(); ++i){
		for(int j=0; j<a[i].size(); ++j){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}*/

	for(int i=0; i<26; ++i){
		t=0;
		for(int j=0; j<a.size(); ++j){
			t=0;
			for(int l=0; l<a[j].size(); ++l){
				if(a[j][l][0]-'a'==i){
					++t;
				}
			}
			ans=(ans<t)?t:ans;
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	string s;

	cin >> n >> k;
	cin >> s;
	cout << solve(n, k, s);

	return 0;
}