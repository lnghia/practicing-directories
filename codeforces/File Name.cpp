#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int n;
    cin >> n >> s;
    vector<int> pos;
    vector<int> t;
    int count=0;
    for(int i=0; i<s.length(); ++i){
        while(s[i]=='x'){
            ++count;
            ++i;
        }
        if(count>=3){
            t.push_back(count);
            pos.push_back(i-count+1);
            count=0;
        }
        count=0;
    }
    int k=0;
    int rs=0;
    if(pos.size()==0){
        cout << 0;
        return 0;
    }
    for(int i=0; i<pos.size(); ++i){
        int j=pos[i];
        while(s[j]=='x'){
            ++j;
            ++rs;
            --t[k];
            if(t[k]<3){
                ++k;
                break;
            }
        }
    }
    cout << rs;
    return 0;
}
