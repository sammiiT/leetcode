//====類似題====
82. Remove Duplicates from Sorted List II
1140. Stone Game II
2056. Number of Valid Move Combinations On Chessboard
1418. Display Table of Food Orders in a Restaurant

//===思路====
1.因為是rotate array, 所以要先考慮左邊遞增或右邊遞增
2.一開始考慮是否有找到數值
3. (1+2)

 if(nums[m]==target) // 已將m 這個條件考慮進去,所以接下來判斷的描述,皆不考慮(nums[m]==target)的情況
 if(nums[m]<nums[r]){//右邊遞增
   //判斷target是否在此區間內, 如果在此區間內用binary search概念繼續運算
   //如果不在此區間內, 跳到左區間
 }else if(nums[m]>nums[r]){//左邊遞增
  //判斷target是否在此區間內, 如果在此區間內用binary search概念繼續運算
  //如果不在此區間內, 跳到右區間
  }else{//如果相等
   //r做位移
 }  
  
//====
bool search(vector<int>& nums, int target){
    int l = 0; r =nums.size()-1;
    while(1<=r){
        int m = l+(r-l)/2;
        if(nums[m]==target) return true;
        if(nums[m]<nums[r]){//右邊遞增
            if(nums[m]<target && target<=nums[r]) l=m+1;//target在範圍之內
            else
                r = m-1;//為什麼不是(r = m;)=> 上述(nums[m]==target)已經把m考慮進去,所以在做跳耀的時候 是r=m-1;
                        //(r=m)表示target在此區間,包括m; 但上述(nums[m]==target)已經不成立, 所以不把m考慮進去; r = m-1;    
        }if(nums[m]>nums[r]){//左邊遞增
            if(nums[l]<=target && nums[m]>target) r = m-1;//(r=m-1)因為nums[m]是大於target, 沒有等於的條件
            else                                          //不用考慮nums[m]>=target, 因為上述(nums[m]==target)已經將此條件考慮進去
                l = m+1;
        }else{//nums[m]==nums[r]
            r--;
        }
    }
    return false;
}
