#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define per(i, a, b) for (int i=a; i>b; --i)
#define ll long long
#define vi vector<int>


using namespace std;

/*int palindrome(string s){
	int i=0, j=s.length()-1;
	if(s.length()%2==0){
		while(i<s.length()/2 && j>=s.length()/2){
			if(s[i]-s[j]!=0){
				return 0;
			}
			++i; --j;
		}
	}
	else{
		while(i<s.length()/2 && j>=(s.length()/2+1)){
			if(s[i]-s[j]!=0){
				return 0;
			}
			++i; --j;
		}
	}
	return 1;
}*/

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m, ans=0, d=0;
		cin >> n >> m;
		string s;
		char c;
		cin >> s;
		rep(i, 0, n/2){
			d+=(s[i]!=s[n-i-1]);
		}
		int p;
		rep(i, 0, m){
			cin >> p >> c;
			d+=s[p-1]!=s[n-p]?0:1;
			s[p-1]=c;
			d-=s[p-1]!=s[n-p]?0:1;
			ans+=(d==0);
		}
		cout << ans << endl;
	}
	return 0;
}
