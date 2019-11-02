class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_product(nums.size()); 
        int n = nums.size();
        
        left_product[0]=1;
        for(int i=1; i<n; ++i){
            left_product[i]=left_product[i-1]*nums[i-1];
        }
        
        int right_product = 1;
        for(int i=n-1 ;i>=0 ;--i){
            left_product[i]=left_product[i]*right_product;
            right_product = right_product*nums[i];
            // right_product = right_product*nums[i];
            // left_product[i]=left_product[i]*right_product;
        }
        
//         for (int i = nums.size() - 1; i >= 0; --i) {
//             res[i] *= right;
//             right *= nums[i];
//         }
        
//         left_product[i] = left_product[i]*right;
//         right = right*nums
        
        return left_product;
    }
};