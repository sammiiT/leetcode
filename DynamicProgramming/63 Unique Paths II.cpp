//===類似題===
64. Minimum Path Sum
980. Unique Paths III
2304. Minimum Path Cost in a Grid
2435. Paths in Matrix Whose Sum Is Divisible by K
//===思路===
(*)
(*)    
-將Grid轉換計算,  遇到0,則無法做運算, 遇到1,可以做運算
 0 | 0 | 0        1 | 1 | 1
---+---+---      ---+---+--- 
 0 | 1 | 0    =>  1 | 0 | 1 
---+---+---      ---+---+---
 0 | 0 | 0        1 | 1 | 1   

-先計算邊界條件;row=0 (0,i)或column=0 (i,0)時的數列,
--如果前一個是0,代表之後都是0
--如果前一個是1,當下的初始值就依據(!obastacleGrid)的數值

-在計算dp[i][j]的步數, 需參考dp[i-1][j]+dp[i][j-1]
--如果(!obastacleGrid==1),則可以經過, 帶入dp[i-1][j]+dp[i][j-1]
--如果(!obastacleGrid==0),則無法經過, 帶入0

//====
int helper0(vector<vector<int>>& obstacleGrid){
    int m = obstacleGrid.size(),n = obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    
    dp[0][0]=!obstacleGrid[0][0];
    for(int i=1;i<m;i++) dp[i][0]= (dp[i-1][0]==0)?0:!obstacleGrid[i][0];
    for(int i=1;i<n;i++) dp[0][i]= (dp[0][i-1]==0)?0:!obstacleGrid[0][i];

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
//            dp[i][j]= (!obstacleGrid[i][j])?(dp[i-1][j]+dp[i][j-1]+!obstacleGrid[i][j]):0;
            dp[i][j]= (!obstacleGrid[i][j])?(dp[i-1][j]+dp[i][j-1]):0;
        }
    }
    return dp.back().back();
}

//=====
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
//====思路2===
(*)多建立一個空間給 dp做運算; vector<vector> dp(m+1,vector<int>(n+1)) ; 多了一個位址
- 初始值會在運算式中建立, 不用單獨建立
- 物理上,實際index的運算直, 會存在另一個新的index上
  dp[i][j] = dp[i-1][j]+dp[i][j-1]
    |           \               \
     \       實際index位址空間    實際index位址空間
     新的index位址空間

- 在dp update的過程運算式中, 將實際的boundary condition 一併做計算.
(1,2) = (0,2) + (1,1)
  |       \       \
   \     實際位址  實際位址
    新的位址
int helper1(vector<vector<int>>& obstacleGrid){
    if(obstacleGrid.empty()||obstacleGrid[0].empty()||obstacleGrid[0][0]==1) return 0;
    int m = obstacleGrid.size(), n= obstacleGrid[0].size();
    vector<vector<long>> dp(m+1,vector<long>(n+1,0));
    
    dp[0][1]=1;
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(obstacleGrid[i-1][j-1]!=0) continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }//(1,2) = (0,1) 
    }    //(1,3) = (0,2)
    return dp[m][n];
}

