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