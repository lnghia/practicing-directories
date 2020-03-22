#include <iostream>

using namespace std;

int main(){
	//tong cac so le (without using if)
	int n, count=0;
	cin >> n;
	int a[n];
	for (int i=0; i<n; ++i){
		cin >> a[i];
		int t=a[i]%2;
		count+=t;
	}
	cout << count ;
	return 0;
}
