#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define per(i, a, b) for (int i=a; i>b; --i)
#define ll long long
#define vi vector<int>


using namespace std;

void swap(string &a, string &b){
	string c;
	c=a;
	a=b;
	b=c;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<string> l(n);
	vector<string> f(n);
	rep(i, 0, n){
		cin >> f[i] >> l[i];
	}
	rep(i, 0, n){
		rep(j, i+1, n){
			if(l[i]>l[j]){
				swap(l[i], l[j]);
				swap(f[i], f[j]);
			}
			if(l[i]==l[j]){
				if(f[i]>f[j]){
					swap(f[i], f[j]);
					swap(l[i], l[j]);
				}
			}
		}
	}
	rep(i, 0, n){
		cout << f[i] << " " << l[i] << endl;
	}

	return 0;
}
