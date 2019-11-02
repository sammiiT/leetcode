class Solution {
public:
    //refer remove duplicate
    void moveZeroes(vector<int>& nums) {
        int pre=0;
        
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==0) continue;
            
            int tmp = nums[pre];
            nums[pre]=nums[i];
            nums[i]=tmp;
            pre++;
        }
    }
};