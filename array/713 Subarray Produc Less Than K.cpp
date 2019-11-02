class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // if (k <= 1) return 0;
        // int res = 0, prod = 1, left = 0;
        // for (int i = 0; i < nums.size(); ++i) {
        //     prod *= nums[i];
        //     while (prod >= k) prod /= nums[left++];
        //     res += i - left + 1;
        // }
        // return res;
        
        if(k<=1) return 0;
        int n = nums.size();
        int res = 0;
        int prod = 1;
        int left = 0;
        
        for(int i=0; i<n; ++i){
            prod = prod*nums[i];
            while(prod>=k) prod = prod/nums[left++];
            res = res + i-left+1;
        }
        return res;
    }
};


