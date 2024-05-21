//===思路===
(*)longest common substring 題型
(*)因為二維dp的兩個字串是相同的字串;所以
- 只討論"右上"區間;  
  

int longestRepeatingSubstring(string& S){
    int m = S.size();
    int res = 0;    
    vector<vector<int>> dp(m,vector<int>(m));
    
    for(int i=0; i<m; ++i){ 
        if(S[i]==S[0]){
            dp[0][i]=1;
        }
    }        

    for(int i=1; i<m; ++i){
        for(int j=i+1; j<m; ++j){
            if(S[i]==S[j]) {
                dp[i][j] = dp[i-1][j-1] +1;
            } else {
                dp[i][j]=0;
            }            
            res =max(res,dp[i][j]);
        }
    }
    return res;
}
