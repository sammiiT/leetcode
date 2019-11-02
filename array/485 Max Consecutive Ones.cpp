class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 0, count=0;
        
        for(int i=0; i<=nums.size(); ++i){
            if(i<nums.size() && nums[i]==1){
                count+=1;
            }else{
                res = max(res,count);
                count=0;
            }
        }
        return res;
    }
};