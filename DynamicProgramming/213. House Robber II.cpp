//=== more challenge ===
256. Paint House
276. Paint Fence
337. House Robber III

//=== 思路 ====
(*)選擇index_0, 則不能選擇 index_(n-1)
   選擇index_(n-1),則不能選擇 index_0

int rob(vector<int>& nums, int left, int right){
  if(right-left+1 <=1) return nums[left];
  vector<int> dp(nums.size(),0);
  dp[left]= nums[left];
  dp[left+1]= (nums[left+1]>nums[left])?nums[left+1]:nums[left];
  for(int i=left+2; i<=right; ++i){
    dp[i]=(dp[i-2]+nums[i],dp[i-1]);
  }
  return dp[right];
}

int rob(vector<int>& nums) {
  if(nums.size()==1) return nums[0];
  return max(rob(nums,0,nums.size()-2),rob(nums,1,nums.size()-1));
}
