#include <bits/stdc++.h>

using namespace std;
int main(){
	int v1, v2, v3, v4;
	int max, min, t=1;
	cin >> v1 >> v2 >> v3 >> v4;
	if (v3<v4) max=v4;
	else max=v3;
	if (2*v3<2*v4) min=2*v3;
	else min=2*v4;
	if (min<max){
		cout << "-1";
		t=0;
		return 0;
	}
	if (v1>2*v4+1) max=v1;
	else max=2*v4+1;
	if (2*v4>2*v1 || 2*v1<max){
		cout << "-1";
		return 0;
		t=0;
	}
	if (v2>2*v4+1) max=v2;
	else max=2*v4+1;
	if (2*v4>2*v2 || 2*v2<max){
		cout << "-1";
		return 0;
		t=0;
	}
	if (t==1){
		cout << 2*v1 << endl;
		cout << 2*v2 << endl;
		cout << min ;
	}
}
