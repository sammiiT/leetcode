class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty()) return false;
        int r = matrix.size();
        int c = matrix[0].size();
        
        int i=0;
        int j = c-1;
        
        
        while(i<r && j>=0)    
        if(target > matrix[i][j]){
            i++;
        }else if(target < matrix[i][j]){
            j--;
        }else{//target==matrix[i][j]
            return true;
        }
        
        return false;
    }
};