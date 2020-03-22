#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, kmin=9999999, kmax=-1;
	cin >> n >> m;
	int a[n], k=0;

	for(int i=0; i<n; ++i){
		cin >> a[i];
	} int t=m, i=0;
	sort(a, a+n);
	k=(a[0]!=a[n-1]);
	kmax=a[n-1]+m;
	if(k==0 || n==1){
		while(t>0){
			if(i>=n)
				i=0;
			++a[i++];
			--t;
		}
		sort(a, a+n);
		cout << a[n-1] << ' ' << kmax;
		return 0;
	} int t1, max=a[n-1];
	//cout << 2 << '\n';
	while(t>0){
		if(a[i]!=max){
			t1=max-a[i];
			if(t1<=t){
				a[i++]+=t1;
				t-=t1;
			}
			else{
				a[i]+=t;
				t=0;
				break;
			}
		}
		else break;
	}
	//cout << 1 << '\n';
	i=0;
	if(t>0){
		while(t>0){
			if(i>=n)
				i=0;
			++a[i++];
			--t;
		}
		sort(a, a+n);
		cout << a[n-1] << ' ' << kmax;
		return 0;
	}
	sort(a, a+n);
	cout << a[n-1] << ' ' << kmax;
 	return 0;
}