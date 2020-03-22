#include <bits/stdc++.h>
#include <string>
#define rep(i, a, b) for (int i=a; i<b; ++i)

using namespace std;

typedef struct svname
{
	string name;
	string ip;
}nm;

typedef struct cmdip
{
	string name2;
	string ip2;
}cip;

bool cmp(nm a,nm b){
    return a.ip<b.ip;
}
int main(){
	int n, m;
	nm a[1000];
	cip b[1000];
	cin >> n >> m;
	rep(i, 0, n)
		cin >> a[i].name >> a[i].ip;
	rep(i, 0, m){
		cin >> b[i].name2 >> b[i].ip2;
		b[i].ip2.erase(b[i].ip2.length()-1, 1);
	}
	sort(a, a+n,cmp);
	rep(i, 0, m){
		int x=0, y=n-1;
		while (x<=y){
			int k=(x+y)/2;
			if (b[i].ip2==a[k].ip){
				cout << b[i].name2 << " " << b[i].ip2 << ";" << " " << "#" << a[k].name << endl;
				break;
			}
			if (a[k].ip>b[i].ip2) y=k-1;
			else x=k+1;
		}
	}
	/*rep(i, 0, m)
		rep(j, 0, n)
			if (b[i].ip2==a[j].ip) cout << b[i].name2 << " " << b[i].ip2 << ";" << " " << "#" << a[j].name << endl;*/
	return 0;
}
