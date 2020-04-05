#include<bits/stdc++.h>
#include<string>

using namespace std;

string solve(string& tmp){
    int i=0, j=tmp.length()-1;

    while(i<j){
        while((tmp[i]<'A' && tmp[i]>'9') || (tmp[i]>'Z' && tmp[i]<'a') || tmp[i]>'z' || tmp[i]<'0'){
            ++i;
        }
        while((tmp[j]<'A' && tmp[j]>'9') || (tmp[j]>'Z' && tmp[j]<'a') || tmp[j]>'z' || tmp[j]<'0'){
            --j;
        }
        if(tolower(tmp[i])!=tolower(tmp[j])){
            return "NO";
        }
        ++i; --j;
    }

    return "YES";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;

    cin >> n;
    cin.ignore();
    while(n--){
        string tmp;

        getline(cin, tmp);
        cout << solve(tmp) << '\n';
    }

    return 0;
}