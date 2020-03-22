int divide(int dividend, int divisor) {
        bool isNegative=((dividend>0 && divisor<0) || (dividend<0 && divisor>0));
        long long res=0;
        long long a=dividend, b=divisor;
        
        a=abs(a); b=abs(b);
        for(int i=31; i>=0; --i){
            if((b<<i)<=a){
                res+=1<<i;
                a-=b<<i;
            }
            if(a<b){
                if(res>INT_MAX && !isNegative){
                    return INT_MAX;
                }
                
                return res*=(isNegative)?-1:1;
            }
        }
        
        if(res>INT_MAX && !isNegative){
            return INT_MAX;
        }
        
        return res*=(isNegative)?-1:1;
    }