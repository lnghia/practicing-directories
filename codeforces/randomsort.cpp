#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	int n;
	while(t--){
		int n;
		cin >> n;
		int a[n], b[1001]={};
		long long ans=1;
		for(int i=0; i<n; ++i){
			cin >> a[i];
			++b[a[i]];
		}
		for(auto i : b){
			if(i!=0){
                int s=1;
                for(int j=1; j<=i; ++j){
                    s=(s*j)%7901;
                }
				ans=(ans*s)%7901;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
