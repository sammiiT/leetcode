class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //dp[i]=min(dp[i-1],dp[i-2])+dp[i];
        
        int n = cost.size();
        vector<int> dp(n+1,0);//0~n
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2; i<=n; ++i){
            if(i<n)
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
            else
            dp[i]=min(dp[i-1],dp[i-2])+dp[i];    
        }
        return dp[n];
    }
};

/*
dp[0] = nums[0]
dp[1] = min(dp[0],dp[-1]) + dp[1] 
dp[2] = min(dp[1],dp[0]) + dp[2]
dp[n] = min(dp[n-1],dp[n-2]) + dp[n];  n>=2
    
dp[0]=10
dp[1]=15
dp[2]=(dp[0],dp[1])+dp[2];
dp[3]=(dp[2],dp[1])+dp[3];
        20     15     0
            */