//===more challenge ===

//===思路===
(*)DFS+memory解 , 也可以用DP解

  
int helper(vector<int>& nums, vector<vector<int>>& dp, int i, int j){
    if(i>j) return 0;
    if(dp[i][j]>0) return dp[i][j];
    int res = 0;
    for(int k=i; k<=j; ++k){
        res = max(res,nums[i-1]*nums[k]*nums[j+1]+helper(nums,dp,i,k-1)+helper(nums,dp,k+1,j));
    }
    dp[i][j] = res;
    return res;
}  

int maxCoins(vector<int>& nums) {
  int n = nums.size();
  vector<vector<int>> dp(n+2,vector<int>(n+2,0));
  nums.insert(nums.begin(),1);
  nums.insert(nums.end(),1);
  return helper(nums,dp,1,n);
}
