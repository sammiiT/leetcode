class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        
        vector<int> dp(n,0);
        
        dp[0]=1;//index = 0, 就是第1階 =>有一種解法
        dp[1]=2;//index = 1, 就是第2階 =>有兩種解法
        for(int i=2; i<n; ++i){
            dp[i] = dp[i-1] + dp[i-2];    
        }
        return dp.back();
        
    }
};
