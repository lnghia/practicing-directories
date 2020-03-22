#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define per(i, a, b) for (int i=a; i>b; --i)
#define ll long long
#define vi vector<int>


using namespace std;



int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x, y, min=1001, max=0, mn=501;
		int ans=-1;
		cin >> n >> x >> y;
		++n;
		int d, m;
		rep(i, 1, n){
			cin >> d >> m;
			if(d<=x && m>=y){
				if(min>d){
					ans=i;
					min=d;
					max=m;
				}
				else if(min==d && max<m){
						ans=i;
						max=m;
				}
			}
		}
		cout << ans << endl;
	}	
	return 0;
}
