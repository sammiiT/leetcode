如何找到boundary condition.
/*
     0 1 2 3
     c b b d
0  c o x x x
1  b x o o x
2  b x o o x
3  d x x x o
dp[2][3] => dp[2][2],dp[3][3] 包圍
dp[1][2] => dp[1][1],dp[2][2]


不討論3~2, 討論2~3  (i<j)的情況, 所以討論右上半部
dp[3][2] => [2][2], [3][3]
dp[3][1] => [2][1], [3][2]
*/

int helper0(string s){
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=n-1; i>=0; i--){
            dp[i][i]=1;//i==j的時候, palindrome數目=1
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];        
                } else {//s[i]!=s[j]
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }        
            }
        }
/*
i最後是0, j最後是n-1;所以
return dp[0][n-1];
*/
        return dp[0][n-1];
}

int longestPalindromeSubseq(string s) {
        return helper0(s);
}
