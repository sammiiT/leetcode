class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        vector<vector<int>> res(r,vector<int>(c,0));
        int x = nums.size(),y = nums[0].size();
        if(x*y!=r*c) return nums;
        
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                
                int k = i*c+j;
                res[i][j]=nums[k/y][k%y];
            }
        }
        return res;
    }
    
    
vector<vector<int>> matrixReshape_OK(vector<vector<int>>& nums, int r, int c) {
    
        int x,y;
        x = nums.size();
        y = nums[0].size();
        
        vector<vector<int>> res(r,vector<int>(c,0));
        
        if(r*c != x*y) return nums;
        
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                int k = i*c+j;
                int row=k/y;
                int col=k%y;
                
                res[i][j]=nums[row][col];
            }
        }
        return res; 
    }
    
    
    
};