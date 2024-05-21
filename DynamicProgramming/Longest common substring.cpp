//===思路===
(*)二維dp陣列
dp[i][j]表示 
-陣列從[0:i], 陣列從[0:j] 最長的common substring

int LCSubstring(string& X, string& Y){
    int m = X.size();
    int n = Y.size();
    int res = 0;
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m;++i){
      for(int j=0;j<=0;++j){
          if(i==0||j==0) dp[i][j]=0;
          else if(X[i-1]==Y[j-1]){
              dp[i][j]=dp[i-1][j-1]+1;
          }else
              dp[i][j]=0;
          res = max(res,dp[i][j]);
      }
    }
    return res;
}
