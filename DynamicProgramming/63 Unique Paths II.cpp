class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(m==0||n==0||obstacleGrid[0][0]==1) return 0;
        
        vector<long> dp(n,0);
        dp[0]=1;//以j=0為base,往下做dynamic programming
        
        //以(0,0)做為基準來擴展, 設定僅d(0)等於1; 與uniquePaths 不同 
        for(int i=0;i<m;++i){
            for(int j=0; j<n; ++j){
                if(obstacleGrid[i][j]==1) dp[j]=0;
                else if(j>0) dp[j]=dp[j]+dp[j-1];// 如果沒有obstacle,則此描述就夠
                //j>0; 將邊界剔除,因為dp[j-1]會變成負值, 從j=1開始
            }
        }
        return dp[n-1];
        
                
// if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         vector<long> dp(n, 0);
//         dp[0] = 1;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (obstacleGrid[i][j] == 1) dp[j] = 0;
//                 else if (j > 0) dp[j] += dp[j - 1];
//             }
//         }
//         return dp[n - 1];
        
    }
};