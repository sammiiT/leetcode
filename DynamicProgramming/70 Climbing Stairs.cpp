class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        
        vector<int> dp(n,0);
        
        dp[0]=1;//一個階梯有1種
        dp[1]=2;//兩個階梯有2種
        for(int i=2; i<n; ++i){
            dp[i] = dp[i-1] + dp[i-2];    
        }
        return dp.back();
        
    }
};