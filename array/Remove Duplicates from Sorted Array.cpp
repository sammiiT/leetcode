class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        int pre=0;
        
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[i-1]){
                pre++;
                nums[pre]=nums[i];
            }//else nums[i]==nums[i-1]
        }
        return pre+1;
    }
    int removeDuplicates_OK2(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int pre = 0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[i-1]){
                pre++;
                nums[pre]=nums[i];
            }
        }
        return pre+1;
    }
    
    int removeDuplicates_OK(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();        
        int prev = 0;
        
        
        for(int i=0; i<nums.size(); ++i){
            if(nums[prev]!=nums[i]){
                prev++;
                nums[prev]=nums[i];
            }    
        }
        return prev+1;
    }
};