class Solution {
public:
    
    
    vector<vector<int>> transpose(vector<vector<int>>& A)
    {
        int r = A.size();
        int c = A[0].size();
        vector<vector<int>> res(c,vector<int>(r,0));
        
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                res[j][i]=A[i][j];
            }
        }
        return res;
    }
    
    //matrix reshape 做法, 錯誤
    vector<vector<int>> transpose_fail(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();
        vector<vector<int>> res(c,vector<int>(r,0));
        
        for(int i =0;i<c;++i){
            for(int j=0;j<r;++j){
                int k = i*r + j;
                
                res[i][j] = A[k/c][k%c];
            }
        }
        return res;
    }
};

//3x2 ->2x3


