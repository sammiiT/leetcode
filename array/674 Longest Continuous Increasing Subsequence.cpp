class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int len=1;
        int res = 0;
        
        for(int i=1;i<=nums.size();++i){
            if(i<nums.size()&&nums[i]>nums[i-1]){
                len+=1;
            }else{
                res = max(res,len);
                len = 1;
            }
        }
        return res;
    }
};