#include <bits/stdc++.h>
#include <vector>

using namespace std;

void init(vector<vector<int> > &a){
	int x, y, l, t=0;
	for (int i=0; i<a.size(); ++i){
		for(int j=0; j<a[i].size(); ++j){
			cin >> x >> y >> l;
			a[x][y]=a[y][x]=l;
			if(x==y && y==l && l==0){
				return;
			}
		}
	}
}

void dfs(vector<vector<int> > a, vector<int>&trace, int x, vector<int> &ans){
	for(int i=0; i<a[i].size(); ++i){
		if(a[x][i] && trace[i]==-1){
			//cout << x << ' ' << i << ' ' << a[x][i] << ' ' << trace[i] << '\n';
			trace[i]=x;
			ans.push_back(i);
			dfs(a, trace, i, ans);
		}		
	}
}

void track(vector<int>&trace, int x, int y){
	while(y!=x){
		cout << y << "<-";
		y=trace[y];
	}
}

void output(vector<int> ans, vector<int> &trace, int x, int y){
	for(int i=0; i<ans.size(); ++i){
		cout << ans[i] << ' ';
	}
	cout << '\n';
	track(trace, x, y);
}

int main(){
	int n, m, x, y, l, StartPoint, Destination;

	cin >> n >> m >> StartPoint >> Destination >> x;

	vector<vector<int> > a(n, vector<int> (n));
	vector<int> trace(n, -1);
	vector<int> ans;

	for(int i=0; i<n; ++i)
		trace[i]=-1;
	trace[0]=-2;
	init(a);
	//cout << a[0][0];
	cout << "pass ok\n";
	dfs(a, trace, x, ans);
	cout <<"pass ok \n";
	output(ans, trace, StartPoint, Destination);
	cout<<"pass ok\n";	
	return 0;
}