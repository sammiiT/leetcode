class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right;
        left = 0,right = nums.size()-1;
       while(left<=right){
           int mid=left+(right-left)/2;       
           if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<nums[right]){
                if(nums[mid]<target && target<=nums[right]) left=mid+1;
               else right=mid-1;
               
            }else{//nums[mid]>nums[right]
                if(target<nums[mid] && nums[left]<=target) right = mid-1;
                else left = mid+1;
            }
        }
        return -1;
    }
    
 int helper0(vector<int>& nums, int target) {
     int l = 0, r = nums.size()-1;
     while(l<=r){
         int m = l+(r-l)/2;
         if(nums[m]<nums[r]){
             if(nums[m]<target && target <=nums[r]) l=m+1;
             else r = m-1;
         }else if(nums[m]>nums[r]){
             if(target<nums[m]&& nums[l]<=target) r = m-1;
             else l=m+1;
         }else if(nums[m]==target){//要優先判斷, 因為此條件有可能會滿足前面兩個判斷式
             return m;             //此判斷式放在最後, 會錯誤  
         }
     }
     return -1;
 }
       
};
