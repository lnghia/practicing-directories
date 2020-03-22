#include<bits/stdc++.h>
#define vi vector<int>
#define rep(i, a, b) for(int i=0; i<a; ++i)
#define per(i, a, b) for(int i=a; i>=b; --i)
#include <time.h>
#include <cstdio>

using namespace std;

int main(){

    long long n;
    cin >> n;
    clock_t start = clock();
    int rs=0;
    long long c=1, t=0;
    long long i=3;
    if(n==1 || n==2){
        cout << n-0;
        return 0;
    }
    while(i<=n){
        i+=2;
        ++t;
    }
    cout << n-t << endl;
    printf("Time: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}

