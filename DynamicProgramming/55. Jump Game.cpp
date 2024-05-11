//===

//===思路===
(*)dp[i]:記錄當下剩下的步數, 判斷此步數是否可以到達last index; 所以:
-每更新一個index, 前一個步數減1, 就是剩下的步數 
-並比較 當下步數nums[i], 若大於前一個剩下的步數, 則更新給dp[i], 不然沿用之前"減1"的步數
dp[i]=max(dp[i-1]-1, nums[i]);

-在執行上述運算之前(在update dp之前); 必須先判斷剩下步數是否<0 ; 也就是判斷 "前一個步數是否能到達下一個index"
(dp[i-1]-1)<0

bool canJump(vector<int>& nums){
    int m = nums.size();
    vector<int> dp(m,0);

    dp[0]=nums[0];

    for(int i=1; i<m; ++i){
//        dp[i]=max(dp[i-1]-1,nums[i]);
//        if(dp[i]<=0 && i<m-1) return false;

        if((dp[i-1]-1)<0) return false;
        dp[i] = max(dp[i-1]-1,nums[i]);
    }
    return true;
}
