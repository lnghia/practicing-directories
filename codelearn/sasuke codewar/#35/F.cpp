#include <bits/stdc++.h>

using namespace std;

bool comp(const string &a, string &b){
    int len=min(a.length(), b.length());
    int ind;

    for(int i=0; i<len; ++i){
        ind=i;
        if(a[i]>b[i]){
            return true;
        }
        else if(a[i]<b[i]){
            return false;
        }
    }

    if(ind<b.length()){
        return b[ind]<=b[0];
    }

    if(ind<a.length()){
        return a[ind]>a[0];
    }

    return true;
}

string maxAddString(std::vector<int> arr, int k)
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    string ans="";
    vector<string> temp;
    int i=arr.size()-1;

    sort(arr.begin(), arr.end());

    while(k--){
        temp.push_back(to_string(arr[i--]));
    }
    
    sort(temp.begin(), temp.end(), comp);
    for(auto& str : temp){
        ans+=str;
    }

    return ans;
}

int main(){
    vector<int> arr={ 59599, 59};
    int k=2;

    cout << maxAddString(arr, k)  << '\n';

    return 0;
}