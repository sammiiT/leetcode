//===類似題===
85. Maximal Rectangle
764. Largest Plus Sign
2201. Count Artifacts That Can Be Extracted
//===思路===

1.建立一個二維dp數組, dp[i][j]表示到達(i,j)位置所能組成的最大正方形"邊長"

2.任意一點 dp[i][j],該點是正方形的右下角;不考慮該點的 右邊, 下邊, 右下邊不用考慮
                                      需考慮左邊, 上,左上

3.若(i,j)為1, dp[i][j]才有可能大於0
若(i,j)為1, 要看dp[i-1][j-1],dp[i][j-1],dp[i-1][j],找其中最小值, 並加上1
                   左上       左          上                     



int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    int res = 0;

    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(i==0||j==0) dp[i][j]=matrix[i][j]-'0';
            else if(matrix[i][j]=='1'){
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
            res = max(res,dp[i][j]);
        }
    }
    return res*res;
}
