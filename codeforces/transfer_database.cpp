#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
ifstream fi ("database.txt");
ofstream fo ("ans.txt");

vector<string> getdata(string s){
	vector<string> val;
	string tmp="";
	int j=0;

	for(int i=0; i<s.size(); ++i){
		if(i==s.size()-1){
			val.push_back(tmp);
		}
		if(s[i]=='-'){
			val.push_back(tmp);
			//cout << tmp << '\n';
			tmp="";
		}
		else{
			tmp+=s[i];
		}
	}

	return val; 
}

string convert(vector<string> s){
	string head="'", tail="'";
	string ans="insert khachhang values(";

	for(int i=0; i<7; ++i){
		ans+=head;
		//cout << s[i] << '\n';
		for(int j=0; j<s[i].size(); ++j){
			ans+=s[i][j];
			//cout << ans << '\n';
		}
		ans+=tail;
		ans+=", ";
	}
	ans+="),";

	return ans;
}

int main(){
	/*fstream f;
	fstream f1;
	f.open("E:\\codeforces\\database.txt", ios::in);
	f1.open("E:\\codeforces\\ans.txt", ios::out);*/
	string tmp;
	vector<string> tmp1;
	string temp="";

	while(fi >> temp){
		//temp="";
		//fi >> temp;
		//cout << temp << '\n';
		tmp1=getdata(temp);
		//cout << tmp1[6] << '\n';
		tmp=convert(tmp1);
		cout << tmp << '\n';
		fo << tmp << '\n';
	}

	return 0;
}