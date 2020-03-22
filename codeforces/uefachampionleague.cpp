#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define per(i, a, b) for (int i=a; i>b; --i)
#define ll long long
#define vi vector<int>


using namespace std;



int main(){
	int t;
	cin >> t;
	while(t>0){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int sum1=0, sum2=0;
		sum1=a+c;
		sum2=b+d;
		if(sum1<sum2){
			cout << 2 << endl;
		}
		else if(sum1>sum2){
			cout << 1 << endl;
		}
		if(sum1==sum2){
			if(b>c){
				cout << 2 << endl;
			}
			else if(b<c){
				cout << 1 << endl;
			}
			else cout << -1 << endl;
		}
		/*else if(b>c){
			cout << 1 << endl;
		}
		else if(c>b){
			cout << 2 << endl;
		}
		else cout << -1 << endl;*/
		--t;
	}
	return 0;
}
