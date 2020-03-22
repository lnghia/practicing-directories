#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int b[1001]={0};
    for(int i=0; i<n; ++i){
        cin >> a[i];
        ++b[a[i]];
    }
    int count=0;
    for(int i=0; i<n; ++i){
        if(b[a[i]]>1){
            ++count;
            b[a[i]]-=1;
            a[i]=-1;
        }
    }
    cout << n-count << endl;
    for(int i=0; i<n; ++i){
        if(a[i]!=-1)
            cout << a[i] << " ";
    }
    return 0;
}
