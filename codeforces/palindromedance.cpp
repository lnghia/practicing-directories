#include <bits/stdc++.h>

using namespace std;

void solve(int t, int n, int a, int b, int ar[]){
	int tmp=0;
	int i=0, j=n-1;
	while(i<=j){
		if(ar[i]!=2 && ar[j]!=2){
			if(ar[i]!=ar[j]){
				cout << -1;
				return;
			}
		}
		else{
			if(ar[i]==ar[j] && ar[i]==2){
				if(i==j)
					tmp+=min(a,b);
				else
					tmp+=min(a,b)*2;
			}
			if(ar[i]!=ar[j]){
				if(ar[i]!=2){
					tmp+=(ar[i]==0)?a:b;
				}
				if(ar[j]!=2){
					tmp+=(ar[j]==0)?a:b;
				}
			}
		}
		++i; --j;
	}
	cout << tmp;
}

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int ar[n], t=((n%2)==0);
	for(int i=0; i<n; ++i){
		cin >> ar[i];
	}
	solve(t, n, a, b, ar);

	return 0;
}