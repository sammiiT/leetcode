class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0||n==0) return 0;
        
        vector<vector<long>> dp(m,vector<long>(n,0));
        
        //initial
        // for(int j=0; j<n; ++j){ dp[0][j]=grid[0][j];}
        // for(int i=0; i<m; ++i){ dp[i][0]=grid[i][0];}
        
        // for(int j=0; j<n; ++j){ 
        //     dp[0][j]=dp[0][j]+grid[0][j];
        // }
        // for(int i=0; i<m; ++i){ 
        //     dp[i][0]=dp[i][0]+grid[i][0];
        // }
        
        dp[0][0]=grid[0][0];
        for(int j=1; j<n; ++j){ 
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=1; i<m; ++i){ 
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                // dp[i][j]=dp[i-1][j-1] + min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1];
        // return 1;
    }
//(1)用遞迴, return min(path_a,path_b); 
/*


if(i==(m-1) && j==(n-1)) {return sum;}
if()


*/    
    
    
//(2)Dungeon Game 地牢遊戲 題: dynamic programming   
};