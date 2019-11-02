class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res({-1,-1});
        if(nums.empty()) return res;
        int n=nums.size()-1;
        int idx;
        idx = binarySearch(nums,target,0,n);
        if(idx==-1) return res;
        
        int tmp = idx;
        for(;tmp>=0;){
            res[0]=tmp;
            tmp = binarySearch(nums,target,0,tmp-1);
        }
        
        tmp = idx;
        for(;tmp>=0;){
            res[1]=tmp;
            tmp = binarySearch(nums,target,tmp+1,n);
        }       
        return res;
    }
    
    
    int binarySearch(vector<int>& nums,int target, int start,int end){
        int left = start;
        int right = end;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else if(nums[mid]>target){
                right= mid-1;
            }else{//nums[mid]==target
                return mid;
            }
        }
        return -1;
    }
};