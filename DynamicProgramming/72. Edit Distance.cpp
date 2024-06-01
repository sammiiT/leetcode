//===more challenge ===
161. One Edit Distance
583. Delete Operation for Two Strings
712. Minimum ASCII Delete Sum for Two Strings
//===思路===
(*)DP 算法
(*)可以做的修改操作為 insert, delete, replace
- 此三種操作都是修改操作, 所以每做一次修改操作, 都要加1
(*)
dp[i][j]表示從word1的"前i個字元 "轉換到word2的"前j字元" 所需的 "步驟量"
先給dp的第一行 和 第一列 賦值
第一行 和第一列對應的,假設是一個空字串
    x   a   b   c   d
x   0   1   2   3   4   
b   1   1   1   2   3 
b   2   2   1   2   3   
c   3   3   2   1   2

邊界初始化:
    x   a   b   c   d
x   0   1   2   3   4   
    |   |   |       |-空集合到 abcd, 一共要change 4次
    |   |   |
    |   |   空集合變ab, 要insert,所以要再加1
    |   空集合變a,要insert
空集合相等不用change

(*)如果遇到相等的,代表不change, 則可用前一個狀態值
dp[i][j]=dp[i-1][j-1]

(*)如果遇到不相等,代表要change,則比較[i-1][j-1], [i-1][j], [i][j-1],看誰比較少
dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;//加1是不相等所以要change


int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    
    dp[0][0]=0;//不做change (insert,  delete,  replace)
    for(int i=1; i<=n; ++i) {
        dp[0][i] = dp[0][i-1]+1;
    }
    for(int i=1; i<=m; ++i) {
        dp[i][0]=dp[i-1][0]+1;
    }
    
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(word1[i-1]==word2[j-1]) {
                dp[i][j]=dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }
    return dp[m][n];
}
