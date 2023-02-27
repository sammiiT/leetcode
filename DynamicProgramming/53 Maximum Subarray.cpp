//===== 相似題 =======
54. Spiral Matrix
978. Longest Turbulent Subarray
2321. Maximum Score Of Spliced Array
1749. Maximum Absolute Sum of Any Subarray
//===思路1===
1.遍歷陣列, 計算每一個節點的總和
2.如果遇到總和是小於當下節點, 則以當下節點作為新的subarray頭, 開始做運算
-- 用max(x,y)來做截斷的動作
--每一次的運算都是是一個sum"總和",
3.每一次的sum都必須再跟過去的maximum做比較, 過去的maximum就是之前的subarray總和

4.回傳最後的maximum
//=====
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


//===思路2===
(*)用2維dynamic programming,會造成 memory exceeded limit
(*)用1維的dynamic programing

//===
int helper4(vector<int>& nums){
    int n = nums.size();
    int res ;
    vector<int> dp(n);
    
    res = dp[0] = nums[0];//以第0個為基準點做運算
    for(int i=1; i<n; i++){
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        res = max(dp[i],res);
    }
    return res;
}
