//===more challenge ===

//===思路===
原字串和子序列都為空,return 1; 因為空字串也是是空字串的一個子序列
原字串不為空, 子序列為空, return 1; 因為空字串是任意字串的一個子序列

int numDistinct(string s, string t) {
  int m = s.size(),n = t.size();
  vector<vector<unsigned long>> dp(n+1,vector<unsigned long>(m+1));

  for(int i=0; i<=m; ++i) dp[0][i]=1;
  for(int i=1; i<=n; ++i){
      for(int j=i; j<=m; ++j){
          if(s[j-1]==t[i-1]) {
              dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
          } else {
              dp[i][j] = dp[i][j-1];
          }
      }
  }
  return dp[n][m];
}
