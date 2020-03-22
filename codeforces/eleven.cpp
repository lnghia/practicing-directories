#include <iostream>
#include <math.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define ll long long

using namespace std;

int main(){
	int n, t=0, i;
	ll a[21];
	a[0]=1; a[1]=1;
	cin >> n;
	rep(i, 0, 21)
		a[i]=a[i-1]+a[i-2];
    rep(i, 0, 21)
        cout << a[i] << " ";
    cout << endl;
	rep(i, 1, n){
		int x=0, y=20;
		while (x<=y){
			int k=(x+y)/2;
			if (a[k]==i){
				t=1;
				break;
			}
			if (a[k]>i) b=k-1;
			else a=k+1;
		}
		// rep(i, 0, 21)
		// 	if (i==a[j]){
		// 		t=1;
		// 		break;
		// 	}
        if (t==1){
            cout << "O";
            t=0;
        }
        else
            cout << "o";
	}
	return 0;
}
