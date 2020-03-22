#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, b;
    cin >> n >> b;
    int a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    vector<int> c;
    int count1=0, count2=0, count3=0, sum=0;
    for(int i=0; i<n; ++i){
        if(a[i]%2==0) ++count1;
        else ++count2;
        if(count1==count2 && i!=n-1){
            c.push_back(abs(a[i]-a[i+1]));
        }
    }
    sort(c.begin(), c.end());
    for(int i=0; i<c.size(); ++i){
        if(sum+c[i]<=b){
            sum+=c[i];
            ++count3;
        }
    }
    cout << count3;
    return 0;
}
