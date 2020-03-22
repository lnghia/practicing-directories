#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    int t[n];
    long long sum=0;
    int j=0;
    long long rs=0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    for(int i=0; i<n; ++i){
        cin >> t[i];
        if(t[i]==1) rs+=a[i];
    }
    int p=k;
    int pos, max=-1;
    for(int i=0; i<k; ++i){
        if(t[i]==0) sum+=a[i];
    }
    max=sum;
    for(int i=1; i<n+1-k; ++i){
        if(t[i+k-1]==0) sum+=a[i+k-1];
        if(t[i-1]==0) sum-=a[i-1];
        if(max<sum) max=sum;
    }
    cout << rs+max;
    return 0;
}
