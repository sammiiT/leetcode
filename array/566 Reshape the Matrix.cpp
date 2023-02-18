//===類似題===
567. Permutation in String
2022. Convert 1D Array Into 2D Array
//===思路===
1.把reshape的maxtrix展開成1維的index
k=i*c+y; =>1維的index 

2.維的index在原matrix中的元素是:
nums[k/x][k%y]

//===
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
