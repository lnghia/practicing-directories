class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count=0;
        
        if(rooms.size()==1){
            return 1;
        }
        
        for(int i=0; i<rooms[0].size(); ++i){
            count+=(rooms[0][i]!=0);
        }
        
        if(!count){
            return 0;
        }
        
        vector<unordered_set<int>> map(rooms.size());
        
        for(int i=0; i<rooms.size(); ++i){
            for(int j=0; j<rooms[i].size(); ++j){
                map[i].insert(rooms[i][j]);
            }
        }
        
        for(int i=1; i<rooms.size(); ++i){
            bool isFound=0;
            
            for(int j=0; j<rooms.size(); ++j){
                if(i==j){
                    continue;
                }
                isFound=(map[j].find(i)!=map[j].end());
                if(isFound){
                    break;
                }
            }
            if(!isFound){
                return 0;
            }
        }
        
        return 1;
    }
};