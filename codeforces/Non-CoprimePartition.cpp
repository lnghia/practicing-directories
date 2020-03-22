#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if(n==1){
		cout << "No";
		return 0;
	}
	vector<int> a;
	vector<int> b(n+1, 0);
	int sum=0;
	for(int i=1; i<=n; ++i){
		sum+=i;
	}
	bool ck=false;
	int t, tt=0, ttt=0;
	for(int i=2; i<=sum/2; ++i){
		if(__gcd(i, sum-i)>1){
			cout << "Yes" << '\n';
			tt=i; ttt=sum-i;
			ck=true;
			break;
		}
	}
	if(!ck){
		cout << "No";
		return 0;
	}
	int count=0;
	while(tt>0){
		if(tt&1==1){
			a.push_back(pow(2, count));
			b[pow(2, count)]=1;
		}
		tt/=2;
		++count;
	}
	cout << a.size() << ' ';
	for(int i=0; i<a.size(); ++i){
		cout << a[i] << ' ';
	}
	cout << '\n';
	cout << n-a.size() << ' ';
	for(int i=1; i<=n; ++i){
		if(b[i]!=1)
			cout << i << ' ';
	}
	return 0;
}