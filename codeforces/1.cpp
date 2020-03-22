#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll pow_1(ll &x, ll &y)
{
    if (y == 0)
        return 1;

    ll t = pow(x, y / 2);
    ll temp = y / 2;

    return t * pow_1(x, temp);
}

int main()
{
    ll x, y;

    cin >> x >> y;

    ll t1 = x, t2 = y;
    cout << pow_1(x, y) * pow(t1, t2 % 2);
    
    return 0;
}
