//=== more challenge ===
2098. Subsequence of Size K With the Largest Even Sum
2767. Partition String Into Minimum Beautiful Substrings
3144. Minimum Substring Partition of Equal Character Frequency
//=== 思路 ===

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n+1);
    
    for(int i=1; i<=n; ++i){
        int curMax = 0;
        for(int j=1; (j<=k) && (i-j>=0); ++j){//從第i個數字往前找j個數字
            curMax = max(curMax,arr[i-j]);
            dp[i] = max(dp[i], dp[i-j] + curMax*j);
        }
    }
    return dp[n];
}
