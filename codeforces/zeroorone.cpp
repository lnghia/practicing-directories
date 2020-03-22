#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define per(i, a, b) for (int i=a; i>b; --i)
#define ll long long
#define vi vector<int>


using namespace std;



int main(){
	int a, b, c;
	cin >> a >> b >> c;
	char ans;
	if(a==b && b==c){
		ans='*';
	}
	else{
		if(a==b){
			ans='C';
		}
		if(b==c){
			ans='A';
		}
		if(a==c){
			ans='B';
		}
	}
	cout << ans;
	return 0;
}
