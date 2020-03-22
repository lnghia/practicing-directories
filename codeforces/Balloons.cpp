 #include<bits/stdc++.h>

 using namespace std;

 int main(){
    int n;
    cin >> n;
    int a[n], sum=0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        sum+=a[i];
    }
    vector<int> ans;
    int s=0, count=0;
    for(int i=0; i<n; ++i){
        s+=a[i];
        ++count;
        ans.push_back(i+1);
        if((sum-s)!=s && i<n-1){
            cout << count << endl;
            for(int j=0; j<ans.size(); ++j){
                cout << ans[j] << " ";
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
 }
