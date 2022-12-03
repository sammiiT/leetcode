class Solution {
public:
    int uniquePaths(int m, int n) {
//dynamic programming
        vector<int> dp(n,1);
//以(1,1)為base做為擴展; 設定 dp的每一個element初始值都為1,與 uniqupaths II不同
        for(int i=1; i<m; ++i){//走到i=1時,對應到j=1~(n-1)的走法數目
            for(int j=1; j<n; ++j){
                dp[j]=dp[j]+dp[j-1];
            }
        }
        return dp[n-1];//最後走到 j=n-1 時的個數
    
//-----------OK-------------------------    
//     vector<vector<int>> dp(m,vector<int>(n,1));//定義初始值,邊界=1(只有一種走法)
//     for(int i=1; i<m; ++i){
//         for(int j=1; j<n; ++j){//從(1,1)開始
//             dp[i][j] = dp[i-1][j]+dp[i][j-1];
//         }
//     }
//     return dp[m-1][n-1];
    
/*

    星號的位置,從空白的地方開始算起,空白預設值=1
    ____________________
    |__|__|__|__|__|___|
    |__|*_|*_|*_|*_|*__|
    |__|*_|*_|*_|*_|*__|
*/    
    
    }
};

//====================================================
 int helper1(int m, int n){//每一列每一列計算
        vector<int> dp(n,1);//第0行的每一個點的走法
        for(int i=1; i<m; i++){//從第1行開始算起
            for(int j=1; j<n; j++){//開始算每一個節點的走法
                dp[j]=dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
 }
 /* dp[j] = dp[j] + dp[j-1] 邏輯; (1,2)走法
dp[j-1]是 (1,1)的總數 ; 四個點的走法
dp[j] 是 (1,2)上一個節點(0,2)的走法
 
     o  o  o  o  o
     o  o  @  o  o
     o  o  o  o  o
 
 */

 int helper0(int m, int n){//i,j第0時; 都是1, 都只有一種走法
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
 }
    
 int uniquePaths(int m, int n) {
        return helper1(m,n);
        //return helper0(m,n);    
 }




