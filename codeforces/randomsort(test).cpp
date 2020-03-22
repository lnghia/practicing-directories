#include<iostream>
#include<iomanip>
#include<string>
#include<time.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include<utility>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int>mps;
    for (int i = 0; i < n; ++i) {
        int it;
        cin >> it;
        mps[it]++;
    }
    ll ans = 1;
    for (auto &it : mps)
        ans = (ans * it.second) % 7901;
    cout << ans << endl;
}
int main() {
    FIO;
    //freopen("input.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}