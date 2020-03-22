#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    int t[n];
    int sum=0;
    int j=0;
    int rs=0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    for(int i=0; i<n; ++i){
        cin >> t[i];
        if(t[i]==1) rs+=a[i];
    }
    int p=k;
    int pos, max=-1;
    for(int i=0; i<n; ++i){
        pos=i;
        while(k>=1){
            if(t[i]==0)
                sum+=a[i];
            ++i;
            --k;
        }
        i=pos+1;
        k=p;
        if(max<sum) max=sum;
        sum=0;
    }
    cout << rs+max;
    return 0;
}
