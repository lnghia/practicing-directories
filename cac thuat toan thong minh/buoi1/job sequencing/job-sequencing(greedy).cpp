#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
    if(a.second.first>b.second.first){
        return 1;
    }
    if(a.second.first==b.second.first && a.second.second>b.second.second){
        return 1;
    }

    return 0;
}

pair<int, int> solve(vector<pair<int, pair<int, int>>>& jobs){
    vector<int> tmpAns, rs;
    vector<int> profit;
    int currTimeUnit;
    bool isZero=1;
    int tmp, sum=0, sum1=0;

    sort(jobs.begin(), jobs.end(), compare);
    tmpAns.resize(jobs[0].second.first, -1);
    profit.resize(jobs[0].second.first, 0);
    tmp=currTimeUnit=jobs[0].second.first-1;

    for(int i=0; i<jobs.size(); ++i){
        if(tmp!=jobs[i].second.first-1){
            tmp=currTimeUnit=jobs[i].second.first-1;
        }
        if(currTimeUnit>=0 && jobs[i].second.first>currTimeUnit && jobs[i].second.second>profit[currTimeUnit]){
            profit[currTimeUnit]=jobs[i].second.second;
            tmpAns[currTimeUnit]=jobs[i].first;
            --currTimeUnit;
        }
    }

    // for(int i=0; i<tmpAns.size(); ++i){
    //     if(tmpAns[i]!=-1){
    //         rs.push_back(tmpAns[i]);
    //     }
    // }

    for(int i=0; i<tmpAns.size(); ++i){
        if(tmpAns[i]!=-1){
            sum+=1;
            sum1+=profit[i];
        }
    }

    return {sum, sum1};
}

int main(){
    vector<pair<int, pair<int, int>>> jobs; // first is job id, second's first is dealine, second's second is profit
    int jobNum, tmp1, tmp2, tmp3;
    pair<int, int> ans;

    cin >> jobNum;
    for(int i=0; i<jobNum; ++i){
        cin >> tmp1 >> tmp2 >> tmp3;
        jobs.push_back({tmp1, {tmp2, tmp3}});
    }

    ans=solve(jobs);

    // for(int i=0; i<ans.size(); ++i){
    //     cout << ans[i] << ' ';
    // }
    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}