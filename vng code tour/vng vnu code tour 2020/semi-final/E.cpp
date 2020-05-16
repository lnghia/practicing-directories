#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct team{
    int name;
    int k, w, s, l;
    bool tmp;

    team(){
        tmp=0;
        k=w=s=0;
        name=-1;
    }
};

struct compare{
    bool operator()(const team& a, const team& b) const {
        if(a.s>b.s){
            return 1;
        }
        else if(a.s<b.s){
            return 0;
        }
        if(a.k>b.k){
            return 1;
        }
        else if(a.k<b.k){
            return 0;
        }
        if(a.w>b.w){
            return 1;
        }
        else if(a.w<b.w){
            return 0;
        }
        if(a.name<b.name){
            return 1;
        }

        return 0;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int gameNum;
    vector<team> v(1001);
    set<team, compare> ans;
    int a, b, m, n;

    cin >> gameNum;
    while(gameNum--){
        cin >> a >> b >> m >> n;
        v[a].name=a;
        v[b].name=b;
        v[a].w+=m;
        v[b].w+=n;
        if(m>n){
            v[a].s+=3;
        }
        else if(m<n){
            v[b].s+=3;
        }
        else{
            v[a].s+=1;
            v[b].s+=1;
        }
        v[a].l+=n;
        v[b].l+=m;
        v[a].k=v[a].w-v[a].l;
        v[b].k=v[b].w-v[b].l;
    }

    for(int i=1; i<=1000; ++i){
        if(v[i].name==-1){
            continue;
        }
        ans.insert(v[i]);
    }

    for(auto& i : ans){
        cout << i.name << ' ' << i.k << ' ' << i.w << ' ' << i.s << '\n';
    }

    return 0;
}