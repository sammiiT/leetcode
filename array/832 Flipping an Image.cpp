class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        
        vector<vector<int>> res(m);
            
        for(int i=0; i<m; ++i){
            for(int j=A[0].size()-1; j>=0; --j){//flip
                res[i].push_back(!A[i][j]);//invert   
            }
        }
        return res;
        
    }
    //(1)flip: horizontal flip
    //(2)
};