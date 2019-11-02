class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count=1;
        int pre = 0;
        
        for(int i=1;i<nums.size();++i){
            if(nums[pre]==nums[i]){
                if(count<2){
                   pre++;
                   count+=1;
                   nums[pre] = nums[i];
                }    
            }else{//nums[pre]!=nums[i]
                count=1;
                pre++;
                nums[pre]=nums[i];
            }
        }
        return pre+1;
    }
};