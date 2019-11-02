class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int res = INT_MIN;
        
        for(int i =0; i<nums.size(); ++i){
            cur = max(cur+nums[i],nums[i]);//reset 節點
            res = max(res,cur);//從過去到現在的總數
        }
        return res;
    }
};