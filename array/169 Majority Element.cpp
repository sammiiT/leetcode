class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 1;
        
        for(int i=1; i<nums.size(); ++i){
            // if(nums[i]==nums[i-1]){
            if(majority==nums[i]){
                count+=1;
            }else{//majority!=nums[i]
                count-=1;
                if(count==0){
                    majority = nums[i];
                    count=1;
                }
            }
        }
        return majority;
    }
};