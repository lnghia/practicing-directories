
    int countSquares(vector<vector<int>>& matrix) {
        int count=0;
        int m=matrix.size(), n=matrix[0].size();
        
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(matrix[i][j]){
                    ++count;
                    if(matrix[i-1][j]==matrix[i][j-1] && matrix[i][j-1] && !matrix[i-matrix[i][j-1]][j-matrix[i][j-1]] ){
                        matrix[i][j]=matrix[i][j-1];
                        count+=matrix[i][j];
                        --count;
                    }
                    else{
                        matrix[i][j]=min(matrix[i-1][j], matrix[i][j-1])+1;
                        count+=matrix[i][j];
                        --count;
                    }
                }
            }
        }
        
        for(auto& i : matrix[0]) count+=(i==1);
        for(int i=1; i<m; ++i) count+=(matrix[i][0]==1);
        
        return count;
    }