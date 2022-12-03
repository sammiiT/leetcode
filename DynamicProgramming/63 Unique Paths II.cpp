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
//====================================================================================
    int helper0(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,1));
  
//建立初始值, 邊界值; 邊界值固定後, 接下來運算都會依賴邊界值      
        dp[0][0] = obstacleGrid[0][0]?0:1; //(0,0)       
        for(int i=1; i<m; i++){ //(1,0)~(m,0)
            if(dp[i-1][0]==0){//如果出現obstacle,則後續都是obstacle 
                dp[i][0]=0; 
                continue;
            }
            if(obstacleGrid[i][0]==1){ dp[i][0]=0; }
        }
        
        for(int i=1; i<n; i++){//(0,1)~(0,n)
            if(dp[0][i-1]==0){//如果出現obstacle,則後續都是obstacle
                dp[0][i]=0;
                continue;
            }
            if(obstacleGrid[0][i]==1){ dp[0][i]=0; }
        }
 
 //從(1,1)開始算起       
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = (obstacleGrid[i][j])? 0 : (dp[i-1][j]+dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
