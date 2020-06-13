#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> cache;

string isPalindrome(int l, int r, string& s){
    int a=l, b=r;

    if(cache.find(l)!=cache.end() && cache[l]==r){
        return "YES";
    }
    if(cache.find(l)!=cache.end() && cache[l]!=r){
        return "NO";
    }

    while(l<r){
        if(s[l++]!=s[r--]){
            return "NO";
        }
        if(cache.find(l)!=cache.end() && cache[l]==r){
            break;
        }
        if(cache.find(l)!=cache.end() && cache[l]!=r){
            return "NO";
        }
    }
    cache[a]=b;

    return "YES";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    string s, ans;
    int l, r;

    cin >> s >> q;
    while (q--){
        cin >> l >> r;
        cout << isPalindrome(l-1, r-1, s) << '\n';
    }
    
    return 0;
}   