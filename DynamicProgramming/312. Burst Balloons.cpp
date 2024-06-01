//===more challenge===
1000. Minimum Cost to Merge Stones
//===思路===
(*)dp 算法
(*)圖解 初始化
                  n
[0] [1]  [2] [3] [4] [5]     
 x   o    o   o   o   x
     i              
   
dp update流程 
- 長度分類;長度從[1:n], 從長度1到長度n
- 以上述長度為基準,遍歷整個數列;
  0  1 2 3 4  
  |--|
    |--|
      |--|
        |--|
長度len為2, 則i最大到 n-len+1 
-有長度,有長度head_index, 可以得到長度end_index
-長度end_index j = i+len-1;

計算區間最大的burst_coin
-大區間由小區間來(dp udpate), 所以區間i~j 可以分為 [i,k-1][k][k+1,j]
dp[i][j] =  max(dp[i][j],nums[i-1]*nums[k]*nums[j+1]+dp[i][j-1]+dp[k+1][j]);

int maxCoins(vector<int>& nums){ 
    int n = nums.size();
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));//
    nums.insert(nums.begin(),1);
    nums.insert(nums.end(),1);
   
    for(int len=1; len<=n; ++len){
        for(int i=1; i<=n-len+1; ++i){//區間len對應的每一個head_inedex
            int j = i+len-1;//長度len的每一個end_index
            for(int k=i;k<=j;++k){//dp update, 
                dp[i][j]=max(dp[i][j],nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
            }
        }  
    } 
    return dp[1][n];//最後的範圍是從[1:n]
}
//===可用 dfs+memeory ===

int helper(vector<int>& nums,vector<vector<int>>& dp, int i, int j){
    if(i>j) return 0;
    if(dp[i][j]) return dp[i][j];
    int res = 0;
    for(int k=i; k<=j; ++k){
        //res = max(dp[i][j],nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j])
        res = max(res,nums[i-1]*nums[k]*nums[j+1]+helper(nums,dp,i,k-1)+helper(nums,dp,k+1,j));
    }
    dp[i][j] = res;
    return res;
}

int maxCoins(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    nums.insert(nums.begin(),1);
    nums.insert(nums.end(),1);

    return helper(nums,dp,1,n);
}
