#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n, w;
    cin >> n >> w;

    long long a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    int max=w, min=0, rs=0;
    for(int i=0; i<n; ++i){
        if(a[i]>0){
            if(max==w){
                max=w;
                min+=a[i];
            }
            else{
                if(max+a[i]<=w){
                    max+=a[i];
                }
                else max=w;
                min+=a[i];
            }
        }
        if(a[i]<0){
            if(min==0){
                min=0;
                max+=a[i];
            }
            else{
                if(min+a[i]>=0)
                    min+=a[i];
                else min=0;
                max+=a[i];
            }
        }
    }

    rs=max-min+1;
    if(rs>0)
        cout << rs;
    else cout << 0;
    return 0;
}
