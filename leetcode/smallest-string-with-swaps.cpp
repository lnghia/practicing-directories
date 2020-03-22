class Solution {
public:
    vector<int> parents, ranks;
    int sLength;
    
    void makeSet(){
        for(int i=0; i<sLength; ++i){
            parents.push_back(i);
            ranks.push_back(0);
        }
    }
    
    int findSet(int u){
        if(parents[u]!=u){
            parents[u]=findSet(parents[u]);
        }
        
        return parents[u];
    }
    
    void unite(int u, int v){
        int up=findSet(u);
        int vp=findSet(v);
        
        if(up==vp){
            return;
        }
        if(ranks[vp]<ranks[up]){
            parents[vp]=up;
        }
        else if(ranks[vp]>ranks[up]){
            parents[up]=vp;
        }
        else{
            parents[vp]=up;
            ++ranks[up];
        }
    }
    
    string smallestStringWithSwaps(string &s, vector<vector<int>>& pairs) {
        sLength=s.length();
        int alphabet[26]={};
        vector<string> tmp(sLength);
        vector<vector<int>> indexList(sLength);
        string ans=s;
    
        makeSet(); 
        for(int i=0; i<pairs.size(); ++i){
            unite(pairs[i][0], pairs[i][1]);
        }
        for(int i=0; i<sLength; ++i){
            int iNodeParent=findSet(i);
            
            tmp[iNodeParent].push_back(s[i]);
            indexList[iNodeParent].push_back(i);
        }
        for(int i=0; i<sLength; ++i){
            if(tmp[i].empty()){
                continue;
            }
            sort(tmp[i].begin(), tmp[i].end());
            for(int j=0; j<tmp[i].length(); ++j){
                ans[indexList[i][j]]=tmp[i][j];
            }
        }
        
        return ans;
    }
};