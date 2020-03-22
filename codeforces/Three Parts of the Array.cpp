#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n], ans=0;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    int i=0, j=n-1;
    long long sum1=a[0], sum2=a[n-1];
    if(n==1){
        cout << 0;
        return 0;
    }
    while(i<j){
        if(sum1==sum2){
            if(ans<sum1) ans=sum1;
            ++i;
            sum1+=a[i];
            //cout << i << " " << j << " " << sum1 << " " << sum2 << " " << ans << endl;
        }
        if(sum1>sum2){
            --j;
            sum2+=a[j];
            //cout << i << " " << j << " " << sum1 << " " << sum2 << " " << ans << endl;
        }
        if(sum1<sum2){
            ++i;
            sum1+=a[i];
            //cout << i << " " << j << " " << sum1 << " " << sum2 << " " << ans << endl;
        }
    }
    cout << ans;
    return 0;
}
