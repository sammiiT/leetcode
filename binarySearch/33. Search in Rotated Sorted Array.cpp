//===more challenge ===
2137. Pour Water Between Buckets to Make Water Levels Equal
//===思路===
(*)分析數列:
左半部任何一個數值, 都大於右半部的最後一個數值
ex: 左半部 {4,5,6,7} , 右半部 {0,1,2}

  左半部 <-|->右半部 
 [4,5,6,7 , 0,1,2]

(*)計算:
-計算得到的m, 在左半部
--判斷target是否就在左半部  if(target<nums[m] && target>=nums[0])
--若不在左半部, 就換區間搜尋
    
-計算得到的m, 在右半部    
--判斷target是否就在右半部  if(target<=nums[n-1] && target>nums[m])
--若不在右半部, 就換區間搜尋

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l=0,r=n-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(nums[m]==target) return m;
        
        if(nums[m]>nums[n-1]){//左半部
            if(target<nums[m] && target>=nums[0]){//一定在左半部
                r = m-1;
            }else{//更改搜尋區間, 在右半部搜尋
                l = m+1;
            }
        } else {//nums[m]<nums[n-1] 右半部
            if(target<=nums[n-1] && target>nums[m]) {//一定在右半部
              l = m+1;  
            } else {//不在此區間, 更改搜勳區間, 搜尋左半部
                r = m-1;
            }
        }
    }
    return -1;        
}
