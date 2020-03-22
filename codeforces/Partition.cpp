
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define per(i, a, b) for (int i=a; i>b; --i)
#define ll long long
#define vi vector<int>


using namespace std;



int main(){
	int n; cin >> n;
	vi a(n);
	int t=0, sum=0, sum1=0, sum2=0, j=0;
	rep(i, 0, n){
		cin >> a[i];
		sum+=a[i];
		if (a[i]<0) t=1;
	}
	if (t==0) cout << sum;
	else{
		rep(i, 0, a.size()) {
		    if (a[i]>=0) sum1+=a[i];
		    if (a[i]<0) sum2+=a[i];
		}
		cout << sum1-sum2;
	}
	return 0;
}
