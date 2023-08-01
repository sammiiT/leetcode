//===類似題===
1940. Longest Common Subsequence Between Sorted Arrays
583. Delete Operation for Two Strings
1092. Shortest Common Supersequence
2207. Maximize Number of Subsequences in a String
//===思路===


int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m,vector<int>(n));

    for(int i=0;i<m;++i) dp[i][0]=(i>0&&dp[i-1][0])?1:(text1[i]==text2[0])?1:0;    
    for(int i=0;i<n;++i) dp[0][i]=(i>0&&dp[0][i-1])?1:(text1[0]==text2[i])?1:0; 
    
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(text1[i]==text2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

//===寫法2====
int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();//8
        int n = text2.size();//7
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];        
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }        
            }
        }
        return dp[m][n];//dp[(m+1)-1][(n+1)-1];
    }
