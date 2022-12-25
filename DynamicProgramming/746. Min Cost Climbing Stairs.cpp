//====類似題=====
747. Largest Number At Least Twice of Others
198. House Robber
1654. Minimum Jumps to Reach Home
351. Android Unlock Patterns

//===思路===
(*)[10,15,20]
top cost.size() => 3階, 要走到第4階才是top; index=3,才是最top
0   1   2   3
10  15  20  0

(*)以階數來算,前面insert一個0
vector<int> dp = cost; => [10,15,20]
dp.insert(dp.begin(),0); => [0,10,15,20] =>前面insert一個0
dp.insert(dp.begin()+dp.size(),0) => [0,10,15,20,0] => 因為走到最top才算數, top不算錢, 所以再增加一階 0

(*)走1步或走2步, 列舉走所有走法的min
-之前的概念; 計數
dp[n]=dp[n-1]+dp[n-2];
dp[1]=1; 數量
dp[2]=2; 數量//(1,1) (2),
for(i = 3; i<n; i++){
    dp[i]=dp[i-1]+dp[i-2];
}
-現在的題意;  dp[i]: 走到第i階, 最少的錢
dp[i] = min(dp[i-1],dp[i-2]) + dp[i] =>加dp[i]是加上當下階層的$$, dp[i]是初始值;等號左邊是走到dp[i]所花費的最少錢
//從dp[u-1]比較少錢, 還是從dp[i-2]比較少? 再加上當下階層的$$(是dp[i]的初始值)    

-初始值定義:
dp[1]=10//走到第1階最少的花費
dp[2]=15//走到第2階最少的花費

-試算:
dp[3]=dp[3]+min(dp[3-1],dp[3-2]);
dp[3]=dp[3]+min(dp[2],dp[1]); = 20+ min(15,10) = 20+10 =30
dp[4]=dp[4]+min(dp[4-1],dp[4-2])=dp[4]+min(dp[3],dp[2])=dp[4]+min(30,15)=0+15=15


//======
int helper0(vector<int>& cost){
        vector<int> dp=cost;
        dp.insert(dp.begin(),0);
        dp.insert(dp.begin()+dp.size(),0);
        for(int i=3; i<dp.size(); i++)
            dp[i]=dp[i] + min(dp[i-1],dp[i-2]);
        return dp[dp.size()-1];
}

int minCostClimbingStairs(vector<int>& cost) {
        return helper0(cost);
}

//======
int helper1(vector<int>& cost)
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

