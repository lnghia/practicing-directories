#include <bits/stdc++.h>

using namespace std;

int findDigits(int n, int k) {
    // Complete this function
    int sum, count=0;
    if (n>0){
        int t=n%10;
        if (t!=0 && k%t==0) sum=++count+findDigits(n/10, k);
        if (t==0 || k%t!=0) sum=count+findDigits(n/10, k);
        //cout << t << " " << sum << endl;
        return sum;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n; int k=n;
        int result = findDigits(n, k);
        cout << result << endl;
    }
    return 0;
}

