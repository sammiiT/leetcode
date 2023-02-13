//===類似題===
36. Valid Sudoku
857. Minimum Cost to Hire K Workers
1975. Maximum Matrix Sum
1326. Minimum Number of Taps to Open to Water a Garden
//===思路===
(*)binary search方式
//====
int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while(l<r){
        int m = l+(r-l)/2;
        if(nums[m]<target) l= m+1; 
        else //nums[m]>=target
            r = m;
    }
    return r;
}
//===
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
//===============================
    int helper_insert(vector<int>& nums, int target, int l, int r){
        int m;
        while(l<=r){
            m = l + (r-l)/2;
            if(nums[m]<target){
                l = m+1;
            }else if(nums[m]>target){
                r = m-1;
            }else{
                return m;
            }        
        }
        return m;//回傳m才是正確, 不能回傳l或m
    }
        
    int searchInsert(vector<int>& nums, int target) {
        int pos;
        pos = helper_insert(nums, target, 0, nums.size()-1);
        
        if(nums[pos]==target){
            return pos;
        }else if(nums[pos]> target){
            return pos;
        }else{// (nums[pos]<target){
            return pos+1;
        }
    }
