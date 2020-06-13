#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> parents;
unordered_set<int> points;
int s=1;
bool temp=1;
int ind=0;
vector<bool> v;

void solve(int& count){
    stack<pair<int, bool>> q;
    bool tmp=0;

    tmp=(points.find(s)!=points.end());
    q.push({s, tmp});
    while(!q.empty()){
        pair<int, bool> curr=q.top(); q.pop();

        count+=(!tree[curr.first].size() && curr.second);
        for(int i=0; i<tree[curr.first].size(); ++i){
            q.push({tree[curr.first][i], points.find(tree[curr.first][i])!=points.end() || curr.second});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int tmp;
    int i=1;
    int count=0;

    cin >> n;

    tree.resize(n+1, vector<int>{});
    while(n--){
        cin >> tmp;
        s=(!tmp)?i:s;
        tree[tmp].push_back(i);
        ++i;
    }
    cin >> n;
    while(n--){
        cin >> tmp;
        points.insert(tmp);
    }

    solve(count);

    cout << count;

    return 0;
}