#include <bits/stdc++.h>
#include <string>
#define rep(i, a, b) for (int i=a; i<b; ++i)

using namespace std;

int check(string s, string c){
    rep(i, 0, s.length()){
        int t=c.find(s[i]);
        if (t!=std::string::npos){
            int t2=c.find(s[i+1]);
            if (t2!=std::string::npos) return i;
        }
    }
    return -1;
}

int main(){
	int n; string s;
	cin >> n >> s;
	string c="euoaiy";
	int t3=check(s,c);
	while(t3!=-1){
        s.erase(t3+1,1);
        t3=check(s,c);
	}
	cout << s;
	return 0;
}
