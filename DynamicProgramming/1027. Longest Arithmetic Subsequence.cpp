int helper0(vector<int>& nums){
        int n = nums.size();
        int res = 0;
        //0 <= nums[i] <= 500  =>  -500 <= 差 <= 500
        //讓dp的index維持在positive, 所以+1000
        //500<=差<=1500 範圍  
        vector<vector<int>> dp(n,vector<int>(1501)); 

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int diff = nums[i]-nums[j]+1000;//讓dp的index維持在positive
          // 當下差值個數總和 = 過去相同插值個數總和 + 當下的差值個數
                dp[i][diff] = dp[j][diff] + 1;
                res = max(dp[i][diff],res);
            }
        }
        return res+1;//沒有算到第一個, 所以要把他加回來
}

int longestArithSeqLength(vector<int>& nums) {
        return helper0(nums);        
}
