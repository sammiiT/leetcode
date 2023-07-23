//===類似題===
099. Two Sum Less Than K

325. Maximum Size Subarray Sum Equals k
1099. Two Sum Less Than K
2110. Number of Smooth Descent Periods of a Stock
//===思路===
(*) sliding window

計算區間 left~i
res = res = i-left+1;

o o o o
\      \
left    i

i-left個數計算為

    +-----------------------第1個
   /       +---------------------第2個  
  /       /       +------------第3個     
 /      /      /      /------- +1計算
|  o   |  o   |  o    | o    
 \      \      \      \-------
  \       \       +--------------
   \       +---------------------  
    +-------------------------
    
//====
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


