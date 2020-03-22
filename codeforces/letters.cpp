#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ++n; ++m;
    long long a[n], b[m];
    for(int i=1; i<n; ++i)
        cin >> a[i];
    for(int i=1; i<m; ++i)
        cin >> b[i];
    int j=1;
    int t=0;
    int sum=0;
    for(int i=1; i<m; ++i){
        if(b[i]>a[j]+t){
            while(b[i]>a[j]+t){
            t+=a[j];
            ++j;
            }
            t-=a[j-1];
            --j;
        }
        if(j==1){
            cout << j << " " << b[i] << endl;
        }
        else{
            cout << j+1 << " " << b[i]-(a[j]+t) << endl;
        }
    }
    return 0;
}
