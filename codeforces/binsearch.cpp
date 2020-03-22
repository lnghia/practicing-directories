/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
for
while
goto
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
int binsearch(int a[], int x, int n, int l=0){
    int r=n-1;
    if (l<=r){
        int k=(l+r)/2;
        if (a[k]==x) return k;
        if (a[k]>x) return binsearch(a, x, k, l);
        if (a[k]<x) return binsearch(a, x, n, k+1);
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l=0, r=n-1;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;

        l=0; r=n-1;
        int it = binsearch(a, x, n, l);

        cout << it;
        cout << endl;
    }
}

