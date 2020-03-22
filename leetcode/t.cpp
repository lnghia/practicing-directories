#include <bits/stdc++.h>

using namespace std;

int main(){
    string ip="www.google.com";

    system(("ping "+ip).c_str());
    cout << "\n TIME: " << fixed << setprecision(2) << (double)(clock()) / CLOCKS_PER_SEC * 1000 << " .ms\n";

    return 0;
}