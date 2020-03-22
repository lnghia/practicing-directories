#include <bits/stdc++.h>

using namespace std;

std::vector<int> rainWater(std::vector<int> a)
{
    int n=a.size();
    int i=0, j=n-1;
    int minWaterLv=min(a[0], a[n-1]);
    int maxWaterLV=max(a[0], a[n-1]);
    vector<int> ans;

    ans.resize(n, 0);
    ans[0]=a[0]; ans[n-1]=a[n-1];
    while(i<j){
        if(a[i]<a[j]){
            ++i;
            if(a[i]<=minWaterLv){
                ans[i]=minWaterLv;
            }
            else{
                ans[i]=a[i];
                minWaterLv=min(a[i], maxWaterLV);
                maxWaterLV=max(a[i], maxWaterLV);
            }
            cout << a[i] << ' ' << a[j] << ' ' << ans[i] << '\n';
        }
        else{
            --j;
            if(a[j]<=minWaterLv){
                ans[j]=minWaterLv;
            }
            else{
                ans[j]=a[j];
                minWaterLv=min(a[j], maxWaterLV);
                maxWaterLV=max(a[j], maxWaterLV);
            }
            cout << a[i] << ' ' << a[j] << ' ' << ans[j] << '\n'; 
        }
    }

    return ans;
}


int main(){
    vector<int> a={10, 5, 14, 8, 10, 13};

    vector<int> ans=rainWater(a);

    for(int i=0; i<ans.size(); ++i){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}