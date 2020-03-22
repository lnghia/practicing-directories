void swap(int &a, int &b){
    int tmp=a;
    
    a=b;
    b=tmp;
}

vector<int> reverse(vector<int> &inp, int i){
    int a=i, b=inp.size()-1;
    
    while(a<inp.size() && b>=0 && a<b){
        swap(inp[a++], inp[b--]);
    }
    
    return inp;
}

vector<int> Solution::nextPermutation(vector<int> &A) {
    int i, j;
    int n=A.size();
    
    for(i=n-2; i>=0; --i){
        if(A[i]<A[i+1]){
            break;
        }
    }
    
    if(i<0){
        sort(A.begin(), A.end());
        
        return A;
    }
    
    for(j=n-1; j>=0; --j){
        if(A[j]>A[i]){
            break;
        }
    }
    
    swap(A[i], A[j]);
    
    return reverse(A, i+1);
}