//=== more challange ===


//=== 思路 ====
(*)dp方法

int longestConsecutive(vector<int>& nums) {
    int m = nums.size();
    int res = 0;
    vector<int> dp(m,1);
    
    sort(nums.begin(),nums.end());

    for(int i=1; i<m; ++i){
        if(nums[i]==(nums[i-1]+1)){
            dp[i]=dp[i-1]+1;
        }else if(nums[i]==nums[i-1]){
            dp[i]=dp[i-1];
        }else if(nums[i]!=(nums[i-1]+1)){
            dp[i] = 1;
        }
        res = max(res,dp[i]);
    }
           //only one element in array  
    return (nums.size()==1)?1:res;
}
