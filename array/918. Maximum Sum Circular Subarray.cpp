//===類似題====
919. Complete Binary Tree Inserter
2183. Count Array Pairs Divisible by K
853. Car Fleet
2289. Steps to Make Array Non-decreasing
//===思路===
(*)參考53. Maximum Subarray
- 只能求出沒有circular狀況下的maximum
- 如果maximum 是發生在橫跨數列的tail和front =>
  
1.遍歷一次數列, 分別記錄maximum和minimum subarray
2.遍歷一次數列, 紀錄數列的total

3.遍歷完數列之後比較 maximum_subarry 和 total-minimum_subarry
-如果是maximum_subarray,  即"解"發生在陣列中間
-如果total-mimimum_subarray, 即"解"橫跨陣列tail和front; minimum_subarray發生在陣列中間

4.還有一種狀況是 maximum_subarray是"負"值,則直接回傳maximum_subarray

(*) (maximum_subarray>0)? max(maximum_subarray,total-minimum_subarry):maximum_subarray; 


(*)此算法跟 一題  subarray maximum product
//====
int maxSubarraySumCircular(vector<int>& nums) {
    int curmax = 0,curmin = 0; 
    //int summax =0,summin = 0;
    int summax =nums[0],summin = nums[0];
    int total=0;
    for(int i= 0;i<nums.size();i++){
        curmax = max(curmax + nums[i],nums[i]);
        summax = max(summax,curmax);

        curmin = min(curmin+nums[i],nums[i]);
        summin = min(summin,curmin);
        total += nums[i];
    }

    return (summax>0)? max(summax,total-summin): summax;
}
