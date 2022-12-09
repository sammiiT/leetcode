    int helper0(vector<int>& nums, int k){
        int n = nums.size();
        int res = 0;
        int left = 0;
        int prod =1;
        
        for(int i=0;i<n;i++){
            prod = prod*nums[i];
            while(left<=i && prod>=k){//left<=i
                prod = prod/nums[left++];    
            }
            res = res +i-left+1;
        }  
        return res;
    }//單一一個的解, 是當...
/*
[2,5,6]  有算到單一6
=>[2,5] 在前面就算過了, 所以計算新的區間
[6],[5,6],[2,5,6]=> 共三種; 就是i-left+1
*/

/*
為什麼要 left<=i??
*/

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        return helper0(nums,k);
    }
