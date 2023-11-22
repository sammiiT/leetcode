//===類似題===
541. Reverse String II
2250. Count Number of Rectangles Containing Each Point
1872. Stone Game VIII
1470. Shuffle the Array
//===思路===
(*)數列一定是奇數個
(*)如果nums[m]==nums[m+1]
左右兩邊是奇數個, 則single一定發生在左半邊
左右兩邊是偶數個, single在右半邊

      V
0 1 1 2 2 3 3  =>左右兩邊,奇數個=>一定發生在"左"半邊

      V
  1 1 2 2 3    =>左右兩邊,偶數個=>一定發生在"右"半邊


nums[m]==nums[m-1]
左右兩邊是奇數個, 則single一定發生在右半邊
左右兩邊是偶數個, single在左半邊
  
      V
1 1 2 2 3 3 4  =>左右兩邊,奇數個 =>一定發生在"右"半邊   

      V
  1 2 2 3 3    =>左右兩邊,偶數個 =>一定發生在"左"半邊

      V
  1 1 2 3 3   =>發生在中間點

//====
int helper0(vector<int>& nums){
    int l = 0, r = nums.size()-1, n = nums.size();
    while(l<r){
        int m = l +(r-l)/2;
        if(nums[m]==nums[m+1]){
            if((n-1-m)%2) r = m;
            else l = m+1;
        } else {
            if(m==0 || nums[m]!=nums[m-1]) return nums[m];
            if((n-1-m)%2) l = m+1;
            else r = m;
        }
    }
    return nums[r];
}

int singleNonDuplicate(vector<int>& nums) {
    return helper0(nums);
}

//=== 寫法2 ===
int singleNonDuplicate(vector<int>& nums) {
      int l = 0, r = nums.size()-1;
      int m = 0;
      while(l<r){
            m = l+(r-l)/2;
        
            //m==0 原因 [1,2,2,3,3]
            //[1,1,2,3,3]中間2是單一個數
            if(m==0||(nums[m]!=nums[m+1] && nums[m]!=nums[m-1])) return nums[m];
            if(m%2){
                  if(nums[m]==nums[m-1]){//at right partition
                      l = m+1;
                  }else{//nums[m]==nums[[m+1] at left partition
                      r = m-1;
                  }
            
            } else {
                  if(nums[m]==nums[m-1]){//at left partition
                      r = m-1;
                  }else{//at right partition
                      l = m+1;
                  }
            }
      }
      return nums[r];        
}



