class Solution {
public:
    int findMin(vector<int>& nums) {
        int left,right;
        left = 0,right=nums.size()-1;
            
        if(nums[left]>nums[right]){
            while(left<right){
                int mid = left +(right-left)/2;
                if(nums[mid]<nums[right]){//右邊升序
                    right = mid;
                }else{//nums[mid]>=nums[mid]
                    left = mid+1;
                }
            }
            return nums[right];
        }
        return nums[0];
    }
};