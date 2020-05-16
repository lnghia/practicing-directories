#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, int>> temp={{2, 17}, {3, 11}, {4, 23}, {1, 12}, {2, 6}, {6, 2}, {11, 4}, {3, 24}, {14, 2}, {9, 4}, {24, 23}, {7, 6}, {23, 4}, {14, 16}, {12, 3}};
    vector<double> t;

    for(auto& pr : temp){
        t.push_back(sqrt(pow(pr.first-15, 2)+pow((pr.second-10), 2)));
        cout << sqrt(pow(pr.first-15, 2)+pow((pr.second-10), 2)) << '\n';
    }
    cout << "--------\n";

    sort(t.begin(), t.end());

    for(auto& n : t){
        cout << n << '\n';
    }

    return 0;
}