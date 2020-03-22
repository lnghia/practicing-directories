#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	int k[q], l[q];
	for(int i=0; i<q; ++i){
		cin >> k[i] >> l[i];
	}
	long long t=n*n;
	vector<vector<int> > a(n, vector<int> (n));
	int x=0, y=0;
	for(int i=1; i<=t/2; ++i){
        while((x+y)%2!=0){
            if(y==(n-1) || y>=n){
                ++x; y=0;
            }
            else ++y;
        }
		a[x][y]=i; ++y;
	}
	for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
        cout << endl;
	}
	x=0; y=1;
	cout << a[4][4] << endl;
	for(int i=t/2+1; i<=t; ++i){
        cout << x << " " << y << endl;
	    while((x+y)%2==0){
            if(y==(n-1) || y>=n){
                ++x; y=0;
            }
            else ++y;
	    }
	    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
        cout << endl;
	}
		a[x][y]=i; ++y;
		cout <<  i << endl;
	}
	for(int i=0; i<q; ++i){
		cout << a[k[i]-1][l[i]-1] << endl;
	}
	return 0;
}
