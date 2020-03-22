#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[3]={}, b[3]={};
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	int sum=0;
	sum+=((b[0]-a[0])>0)?(b[0]-a[0]):0;
	sum+=((b[1]-a[1])>0)?(b[1]-a[1]):0;
	sum+=((b[2]-a[2])>0)?(b[2]-a[2]):0;
	cout << sum;
	return 0;
}