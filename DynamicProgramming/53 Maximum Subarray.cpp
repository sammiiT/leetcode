class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int res = INT_MIN;
        
//(1)當數列中有負值, 才能用此方法 => 全部都(+)不能用此方法        
//(2)不能重新排列(不能sort), 因為是求subarray        
        for(int i =0; i<nums.size(); ++i){
            cur = max(cur+nums[i],nums[i]);//reset 節點
            res = max(res,cur);//從過去到現在的總數
        }
        return res;
    }
};
