//=== more challenge ===
213. House Robber II
256. Paint House
276. Paint Fence
//=== 思路 ===
(*)數列 [100 1000 100]
dp[0]=100
dp[1]=(nums[1]>nums[0])?nums[1]:nums[0]; => dp[1] =1000
dp[2]=max(dp[2-2]+nums[2],dp[2-1]) = max(dp[0]+nums[2],dp[1]) = max(100+100,1000)=1000

(*)數列[100 1 100]
dp[0]=100;
dp[1]=(nums[1]>nums[0])?nums[1]:nums[0]; => dp[1]=100
dp[2]=max(dp[0]+nums[2],dp[1])=max(100+100,100) = 200


int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,0);
    
    if(n==1) return nums[0];
    
    dp[0] = nums[0];
    dp[1] = ((nums[1]>nums[0])?nums[1]:nums[0]);
    
    for(int i=2;i<n;++i){
        dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[n-1];        
}
