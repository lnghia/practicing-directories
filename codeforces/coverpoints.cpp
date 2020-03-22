#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    int max1=-1;
    for(int i=0; i<n; ++i){
        cin >> a[i].first >> a[i].second;
        if(max1<(a[i].first+a[i].second)){
            max1=(a[i].first+a[i].second);
        }
    }
    cout << max1;
    return 0;
}
