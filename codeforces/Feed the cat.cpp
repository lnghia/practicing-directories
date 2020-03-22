#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int hh, mm;
    cin >> hh >> mm;
    int h, d, c, n;
    cin >> h >> d >> c >> n;
    double rs;
    int t=hh*60;
    double hun=(20*60-t)*d;
    hun+=h;
    hun=(double)hun/(double)n*(double)c-(double)hun/(double)n*(double)c*20/100;
    if((double)h/(double)n*(double)c<hun) rs=(double)h/(double)n*(double)c;
    else rs=hun;
    cout << setprecision(8) << rs;
    return 0;
}
