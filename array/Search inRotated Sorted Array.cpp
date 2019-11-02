class Solution {
public:
    int search(vector<int>& nums, int target) {
       
        int left, right;
        left = 0,right = nums.size()-1;
   while(left<=right){
       
       int mid=left+(right-left)/2;
        // if(nums[mid]<nums[right]){
        //    if(nums[mid]<target && target<=nums[right]) left=mid+1;
        //    else right=mid-1;
        // }else if(nums[mid]>nums[right]){
        //    if(target<nums[mid] && nums[left]<=target) right = mid-1;
        //    else left = mid+1;    
        // }else{//target ????????????, ?????????
        //     return mid;   
        // }
       
       
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
        
/*        
        while(left<=right){
            int mid = left+(right-left)/2;
            
            if(nums[mid]<nums[right]){//????
                if(nums[mid]<target && target<=nums[right]) left=mid+1;
                else{
                    right=mid-1;
                }    
                
            }else if(nums[mid]>nums[right]){//????
                if(target<nums[mid] && nums[left]<=target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
                    
            }else{//nums[mid]==target
                return mid;
            }
            
        }
*/        
        return -1;
    }
    
/*
   while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<nums[right]){
            if(nums[mid]<target && nums[right]>=target) left = mid+1;
            else right = mid-1;
        }else{
            if(nums[left]<=target && nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
    }
    return -1;
       
*/    
    
    /*
       while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<nums[right]){
            if(nums[mid]<target && nums[right]>=target) left = mid+1;
            else right = mid-1;
        }else{
            if(nums[left]<=target && nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
    }
    */
    
};