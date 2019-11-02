class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
//int right =nums.size()-1;//??target>end(),????? nums.size()-1,????,????nums.size()
        int right = nums.size();      
        
        while(left<right){
            int mid = left + (right-left)/2;
            
            if(nums[mid]<target){
                left = mid+1;
            }else{///nums[mid]>=target
                right = mid;
            }
        }//left == right
        
        
        return right;
    }
};