class Solution {
public:
    #define ll long long
    
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    bool isHappy(int n) {
        ll num=n;
        bool ans;
        map<int, int> cache;
        
        while(1){
            int tmp=0;
            
            while(num){
                int t=num%10;
                tmp+=t*t;
                num/=10;
            }
            if(cache.find(tmp)!=cache.end()){
                return 0;
            }
            num=tmp;
            cache.insert(tmp);
            if(num==1){
                return 1;
            }
        }
        
        return ans;
    }
};