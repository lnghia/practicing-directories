#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<b; ++i)
#define per(i, a, b) for (int i=a; i>b; --i)
#define ll long long
#define vi vector<int>


using namespace std;



int main(){
	long long a, b, t, ck=0, l;
	cin >> a >> b;
	while (a!=0 && b!=0){
        if (a-2*b<0 && b-2*a<0) break;
        if (a>=2*b && b!=0){
            t=a/(b+b);
            a-=t*2*b;
        }
        if (b>=2*a && a!=0){
            t=b/(a+a);
            b-=t*2*a;
        }
	}
	cout << a << " " << b;
	return 0;
}

