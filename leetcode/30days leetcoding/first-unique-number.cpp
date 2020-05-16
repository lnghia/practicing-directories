class FirstUnique {
public:
    queue<int> q;
    queue<int> uniqueNums;
    unordered_map<int, int> cache;
    stack<int> temp;
    
    FirstUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        for(auto& num : nums){
            q.push(num);
            if(cache.find(num)!=cache.end()){
                if(uniqueNums.front()==num){
                    uniqueNums.pop();
                }
                ++cache[num];
            }
            else{
                cache[num]=0;
                uniqueNums.push(num);
            }
        }
    }
    
    int showFirstUnique() {
        while(!uniqueNums.empty()){
            if(!cache[uniqueNums.front()]){
                return uniqueNums.front();
            }
            uniqueNums.pop();
        }
        
        return -1;
    }
    
    void add(int value) {
        q.push(value);
        
        if(cache.find(value)!=cache.end()){
            ++cache[value];
            if(uniqueNums.front()==value){
                uniqueNums.pop();
            }
        }
        else{
            cache[value]=0;
            uniqueNums.push(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */