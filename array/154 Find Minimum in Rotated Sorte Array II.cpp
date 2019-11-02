class Solution {
public:
    int findMin(vector<int>& nums) {
        
        // int n = nums.size();
        // if(n<=0) return -1;
        // int left,right;
        // left = 0;
        // right = n-1;
//         if(nums[left]>nums[right]){//有重複數字出現, 則不能用此方式,因為[2,2,0,2,2,2]即不滿足此判別式
//             while(left!=right){//用left<right, 最後輸出為lef == right的值, 比較難判斷是否為minimum
//                 int mid = left+(right-left)/2;
//                 if(nums[mid]<nums[right]){
//                     right = mid;    
//                 }else if(nums[mid]>nums[right]){
//                     left = mid;
//                 }else{//nums[i]==nums[right]
//   //{2, 2, 2, 2,2,2,2,2, 0, 2, 2, 2, 2, 2, 2, 2, 2}                  
//   //執行時情況狀況, 從最右邊向左逼近;每次進一位;到0; 最花時間
//   //再二分法執行left = mid, 一直到left = right-1; 
                    
//                     right = right-1;
//                 }
//             }
//             return min(nums[right],nums[left]);
//         }
//         return nums[0];

        
        if (nums.empty()) return 0;
        int left = 0, right = nums.size() - 1, res = nums[0];
        while (left < right - 1) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {
                res = min(res, nums[left]);
                left = mid + 1;
            } else if (nums[left] > nums[mid]) {
                res = min(res, nums[right]);
                right = mid;//
            } else ++left;//有等於的狀況出現;數字duplicate
        }
        res = min(res, nums[left]);
        res = min(res, nums[right]);
        return res;
        
        
        
        
        
    }
};