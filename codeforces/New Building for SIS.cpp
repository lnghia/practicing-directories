#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    int t[k], f[k], t2[k], f2[k];
    for(int i=0; i<k; ++i){
        cin >> t[i] >> f[i] >> t2[i] >> f2[i];
    }
    int ans[k]={};
    for(int i=0; i<k; ++i){
        if(t[i]==t2[i]){
            if(f[i]==f2[i]){
                ans[i]=0;
            }
            if(f[i]<f2[i]){
                ans[i]=f2[i]-f[i];
            }
            if(f[i]>f2[i]){
                ans[i]=f[i]-f2[i];
            }
        }
        else{
            while(t[i]>t2[i]){
                if(f[i]>b){
                    ans[i]+=f[i]-b;
                    f[i]=b;
                }
                if(f[i]<a){
                    ans[i]+=a-f[i];
                    f[i]=a;
                }
                --t[i];
                ++ans[i];
            }
            while(t[i]<t2[i]){
                if(f[i]>b){
                    ans[i]+=(f[i]-b);
                    f[i]=b;
                    //cout << f[i] << " " << t[i] << " " << ans[i] << endl;
                }
                if(f[i]<a){
                    ans[i]+=(a-f[i]);
                    f[i]=a;
                    //cout << f[i] << " " << t[i] << " " << ans[i] << endl;
                }
                ++t[i];
                ++ans[i];
                //cout << f[i] << " " << t[i] << " " << ans[i] << endl;
            }
            if(f[i]<f2[i]){
                ans[i]+=f2[i]-f[i];
            }
            if(f[i]>f2[i]){
                ans[i]+=f[i]-f2[i];
            }
            //cout << f[i] << " " << t[i] << " " << ans[i] << endl;
        }
    }
    for(int i=0; i<k; ++i)
        cout << ans[i] << endl;
    return 0;
}
