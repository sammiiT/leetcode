
//===思路==
(*) in-place : 用swap執行
1.先對角線互換

    o   o  o
     \    \    
    o | o  o
     \ \   
       \ \
    o   o \>o
    
2.上下做flip

    o   o   o
   /   /   /
  | o | o | o
   \   \   \
    o   o   o
    
//====
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; ++i){
            for(int j=0;j<n-i;++j){
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
        for(int i=0; i<n/2; ++i){
            for(int j=0;j<n;++j){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
    }
};
