//===類似題===
1286. Iterator for Combination
2787. Ways to Express an Integer as Sum of Powers
//===思路===
(*)dp[i] = 個數

(*)數列從 [1~target] 分別做比較
- [1~target]每一個數字 與 nums[i]做比較, 當[1~target]數值比nums[i]大,則

for(int i=1;i<=target;++i){
    for(int a:nums) { 
        //每一個target與
        if(i>=a) dp[i] = dp[i] + dp[i-a];
                   |        |       |
                   |        |       \ 
                   |    之前的個數    當下差值所對應個數(屬於之前的個數) 
             taret所對應的新個個數
    }    
}


//===
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target){
        // vector<int> dp(target + 1);//錯誤
       
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i >= a) dp[i] += dp[i - a];
            }
        }
        return dp.back();
        
//         vector<int> dp(target+1,0);
        
//         dp[0]=1;//why??
//         for(int i=1; i<=target; ++i){
//             for(auto a:nums){
//                 // if(i>=a) dp[i] = dp[i]+dp[i-a];
//                 if (i >= a) dp[i] += dp[i - a];
//             }
//         }
//         return dp.back();
    }
};



//     int combinationSum4(vector<int>& nums, int target) {
//         vector<vector<int>> res;
//         vector<int> out;
//         sort(nums.begin(),nums.end());
//         helper(nums, target, 0, out, res);
        
//         return res.size();
//     }
    
    
//     void helper(vector<int>& nums, int target, int start, vector<int> &out, vector<vector<int>>& res){
//         if(target<0) return;
//         if(target==0){ res.push_back(out); return; }
        
//         for(int i=start; i<nums.size(); ++i){
//             out.push_back(nums[i]);
//             helper(nums, target-nums[i], i, out, res);
//             out.pop_back();
//         }
//     }
