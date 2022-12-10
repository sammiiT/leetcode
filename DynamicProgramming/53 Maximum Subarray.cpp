class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int res = INT_MIN;
        
//(1)當數列中有負值, 才能用此方法 => 全部都(+)不能用此方法; 且全部都+ 的解, 就是當下的陣列        
//(2)不能重新排列(不能sort), 因為是求subarray        
        for(int i =0; i<nums.size(); ++i){
            cur = max(cur+nums[i],nums[i]);//reset 節點
            res = max(res,cur);//從過去到現在的總數
        }
        return res;
    }
};


/*   memory limit exceeded */   
//dynamic programming造成記憶體使用過度
    int helper3(vector<int>& nums){
        int n = nums.size();
        int res;
        vector<vector<int>> dp(n,vector<int>(n));
        res = nums[0];
        for(int i=0; i<n; i++){
            for(int j=i;j<n;j++){
                dp[i][j]= (i==j)?(nums[i]):(dp[i][j-1]+nums[j]);
                res = max(dp[i][j],res);
            }
        }
        return res;
    }

//沒考慮到i==j的情況,會有錯誤
int helper2(vector<int>& nums){
    int n = nums.size();
    int res;
        vector<vector<int>> dp(n,vector<int>(n));
        res = nums[0];
/*
要考慮(i==j)的情況
[-2,1] => [1]
*/        
        for(int i=0; i<n; i++){
            dp[i][i]=nums[i];
            for(int j=i+1;j<n;j++){
                dp[i][j]=dp[i][j-1]+nums[j];
                res = max(dp[i][j],res);
            }
        }
        return res;
}
