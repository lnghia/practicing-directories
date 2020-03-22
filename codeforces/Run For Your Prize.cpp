#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define ll long long

using namespace std;

int main(){
	ll n; cin >> n;
	ll a[n+1], t, t2, k=1, l=-1, p=-1;
	rep(i, 1, n){
        cin >> a[i];
        if (a[i]>500000 && k==1){ l=i; k=0;}
        if (a[i]==500000) p=i;
	}
	if (p!=-1){
        cout << a[p]-1;
        return 0;
	}
	if (l==-1){
        cout << a[n]-1;
        return 0;
	}
	if (n==1){
        t=a[l-1]-1; t2=pow(10, 6)-a[l];
        if (t>=t2) cout << t2;
        else cout << t;
        return 0;
	}
	if (l==1) t=0;
	else t=a[l-1]-1; t2=pow(10, 6)-a[l];
	if (t>=t2) cout << t;
	else cout << t2;
	return 0;
}
