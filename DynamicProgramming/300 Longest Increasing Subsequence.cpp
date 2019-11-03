﻿class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        vector<int> dp(nums.size(),1);
        int res=0;
  
/*
                i   //固定i
          j         //每次j的變化,會重新改變dp[i]的值
    1, 2, 3, 4, 5...
*/        
        
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i]){
                                        //"+1"加上當下nums[i]的個數    
                    dp[i]=max(dp[i], dp[j] + 1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};