#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define per(i, a, b) for (int i=a; i>b; --i)
#define ll long long
#define vi vector<int>


using namespace std;



int main(){
	int n, r;
	cin >> n >> r;
	int ans[n+1]={};
	int t;
	rep(i, 0, r){
		cin >> t;
		ans[t]=1;
	}
	t=0;
	rep(i, 1, n+1){
		if(ans[i]==0){
			cout << i << " ";
			t=1;
		}
	}
	if(t==0){
		cout << '*' << " ";
	}
	return 0;
}
