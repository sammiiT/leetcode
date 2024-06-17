//=== more challenge ===
983. Minimum Cost For Tickets
2218. Maximum Value of K Coins From Piles
2224. Minimum Number of Operations to Convert Time
//===思路 ===
(*)vector<int> dp(amount+1,amount+1)
每一個element,初始值要設定為amount+1
element的index, 代表coins 可以組成的數值
dp[index]代表可組成數值的最少數目

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(1+amount,amount+1);
    dp[0]=0;

    for(int i=1; i<=amount; ++i){
        for(int j=0; j<coins.size(); ++j){
            if(coins[j]<=i){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);// +1是,使用"一個" coins[j]
            }                                     // 組成i-coins[j],需要的最少coin數
        }
    }
    return dp[amount]>amount?(-1):dp[amount];
}
