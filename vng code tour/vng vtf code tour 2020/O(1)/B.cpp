#include <bits/stdc++.h>

using namespace std;

void a(vector<long long>& t, int u, int v){
    for(int i=u; i<=v; ++i){
        t[i]=0;
    }
}

void b(vector<long long>& t, int u, int v){
    long long sum=0;

    for(int i=u; i<=v; ++i){
        sum+=t[i];
    }

    cout << sum << '\n';
}

void c(vector<long long>& t, int u, int v, int d){
    for(int i=u; i<=v; ++i){
        t[i]+=(long long)d;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    vector<long long> stocksVal;
    int tmp;
    int u, v, d;

    cin >> n >> q;
    while(n--){
        cin >> tmp;
        stocksVal.push_back(tmp);
    }

    while(q--){
        cin >> tmp;
        if(tmp==1){
            cin >> u >> v;
            a(stocksVal, u-1, v-1);
        }
        else if(tmp==2){
            cin >> u >> v;
            b(stocksVal, u-1, v-1);
        }
        else{
            cin >> u >> v >> d;
            c(stocksVal, u-1, v-1, d);
        }
    }

    return 0;
}