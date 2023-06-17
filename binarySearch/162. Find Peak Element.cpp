//===類似題===
2682. Find the Losers of the Circular Game
852. Peak Index in a Mountain Array
1901. Find a Peak Element II
2137. Pour Water Between Buckets to Make Water Levels Equal

//===思路====
(*)將邊界 定義在index=1 ~ index=nums.size()-1
-index=1開始是因為first-middle會落在index=0的位置, 
-if(nums[m]>nums[m+1] && nums[m]>nums[m-1]) 沒有設定index=1,前面描述會錯誤 (index出現負值)
  
 while(l<r) => 最後l==r 會落在 index=1 或index=nums.size()-1
   
   0  1  2  3  4  5  6 
   x  x  x  x  x  x  x 
 
(*) 如果落在index=1, index=nums[size-1]
nums[r]>nmus[r-1]  大於前一個 , 則回傳r
小於前一個, 回傳r-1
 
//====
int findPeakElement(vector<int>& nums){
    int l=1,r=nums.size()-1;
    int m;

    if(nums.size()==1) return 0;//如果只有一個元素, 直接回傳

    while(l<r){
        int m = l+(r-l)/2;
        if(nums[m]>nums[m+1] && nums[m]>nums[m-1]) return m;

        if(nums[m]<nums[m+1]) l=m+1;
        else// nums[m]>=nums[m+1]
            r=m;
    }
    return nums[r]>nums[r-1]?r:r-1;
}
