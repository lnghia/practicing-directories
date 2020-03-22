#include <bits/stdc++.h>
#include <vector>

using namespace std;

void dfs(vector<vector<pair<int, int> > > a, int i, int trace[], int m){
	for(int j=0; j<a[i].size(); ++j){
		if(trace[a[i][j].first]==-1){
			trace[a[i][j].first]=i;
			dfs(a, a[i][j].first, trace, m);
		}
	}
}

void result(vector<vector<pair<int, int> > > a, int trace[], int s, int f){
	for(int i=0; i<a[s].size(); ++i){
		cout << a[s][i].first << ' ';
	}
	cout << '\n';
	int i=f;
	while(i!=s){
		cout << i << "<-";
		i=trace[i];
	}
}

int main(){
	int n, ii, jj, val, s, f, m;
	pair<int, int> t;

	cin >> n >> m >> s >> f;
	++m;
	vector<vector<pair<int, int> > > a(m);
	int trace[m];

	for(int i=0; i<m; ++i){
		trace[i]=-1;
	}
	for(int i=1; i<=n; ++i){
		cin >> ii >> jj >> val;
		t.first=jj; t.second=val;
		a[ii].push_back(t); 
		t.first=ii;
		a[jj].push_back(t);
	}
	trace[s]=-2;
	for(int i=1; i<a.size(); ++i){
		cout << i << ' ';
		for(int j=0; j<a[i].size(); ++j){
			cout << a[i][j].first << " ";
		}
		cout << '\n';
	}
	dfs(a, s, trace, m);
	result(a, trace, s, f);

	return 0;
}