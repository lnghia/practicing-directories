#include <bits/stdc++.h>

#define ll long long

using namespace std;

string jumpingFrog(std::vector<int> a)
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    ll pos;

    if (a[0] == a[1])
    {
        return to_string(a[0]);
    }

    if (((a[0] - a[1]) % (a[3] - a[2])) || (a[2] == a[3]))
    {
        return "NO";
    }

    pos = ((ll)((ll)a[0] - (ll)a[1]) / (ll)((ll)a[3] - (ll)a[2])) * (ll)a[2] + (ll)a[0];

    return to_string(pos);
}

int main()
{
    vector<int> m = {1, 3, 2, -2};

    cout << jumpingFrog(m) << '\n';

    return 0;
}