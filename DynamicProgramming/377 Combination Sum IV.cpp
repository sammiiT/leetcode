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
