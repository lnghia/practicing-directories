#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string a[] ={"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	int t=1867+n, count=0;
	for(int i=1868; i<=t; ++i){
		if((i%4==0 && i%100!=0) || (i%400)==0)
			++count;
	}
	int t1=count*366+365*(n-count), i=7;
	if(n==0){
		cout << a[7];
		return 0;
	}
	while(t1--){	
		++i;
		if(i>7){
			i=1;
		}
	}
	cout << a[i];
	return 0;
}