//===思路====
(*)DP + 接龍
0. 建立dp數列, 每一數列的對應值為陣列  vector<vector<int>>
-陣列的排列是依據倍數由小到大; 如 [2,4,6,8], [3,6,9,12]
- 所以比較是否為倍數時, 只要比較最後一個數, 只要能整除最後一個數, 則能整除所有的樹

1. 排列 ascending,並對dp做初始化
2. dp update
比較 [j:i), j=0開始
條件:如果nums[i]可以整除dp[j]的最後一個;做dp更新
dp[i]=dp[j]
dp[i].push_back(nums[i])//因為dp[j]不包含nums[i]

條件: dp[i].size() < dp[j].size()+1
dp當下更的陣列大小, 小於之前的陣列dp[j].size()+1; 加1的目的是因為之前的dp[j]不包含 nums[i],所以要加1
如:[4,8,10,240],當運行到i=3時,[i]=240
i=3,j=1 => dp[i]=[4,8,240]
i=3,j=2 => dp[i]=[10,240] => dp[3].size()==3 > d[2].size()=1 =>所以不udpate dp;
  
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int m = nums.size();
    vector<vector<int>> dp(m);
    vector<int> res;

    sort(nums.begin(),nums.end());

    for(int i=0; i<m; ++i){
        dp[i].push_back(nums[i]);        
    }

    for(int i=1; i<m; ++i){
        for(int j=0; j<i; ++j){
            if(nums[i]%dp[j].back()==0 && (dp[i].size()<dp[j].size()+1)){
                dp[i]=dp[j];
                dp[i].push_back(nums[i]);
            }        
        }
        res = dp[i].size()>res.size()?dp[i]:res;
    }
    return res.size()?res:nums;
}

//===思路2===
(*)再研究
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),0),parent(nums.size(),0),res;
        int mx=0,mx_idx=0;
        for(int i=nums.size()-1; i>=0; --i){
            for(int j=i; j<nums.size(); ++j){
                if(nums[j]%nums[i]==0&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                    parent[i]=j;
                    if(mx<dp[i]){
                        mx=dp[i];
                        mx_idx=i;
                    }
                }
            }
        }
        for(int i=0; i<mx; ++i){
            res.push_back(nums[mx_idx]);
            mx_idx=parent[mx_idx];
        }
        return res;
    }
};
  
