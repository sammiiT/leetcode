//===類似題===
411. Minimum Unique Word Abbreviation
1011. Capacity To Ship Packages Within D Days
1231. Divide Chocolate
2305. Fair Distribution of Cookies

//===思路===
(*)binary search
1.先求算分割成n個的minimum largset和分割成1個的minimum largest
2.以first_middle作為 minimum largest
-如果first_middle可以繼續分割, 分割數<=k(期望分割數), 所以設定較小的minimum_largest; r = m;
- 如果first_middle運算的分割數>k(期望分割數), 則要設定較大的minimum_largest; l = m+1

(*)如果largest數值越大, 代表可以分割的數區間越少, 
- 回傳 true, 要往較小的largest方向移動  r=m;
(*)如果largest數值越小, 代表可以分割的區間越多 
-回傳false, 要往較大largest的方向移動 l=m+1;

(*)概念, 與1891. Cutting Ribbons 思路相同
- 以數值, 來求出條件所需的 segament數目
-此數值的範圍, 從數列中的最小值來定義 [1: minimum_element_value]
- 先定義 length大小, 求出對應的segement; 判斷此segement是否滿足題意 k 

此題目:
- 以數值, minimum_largest 來求出 對應的segement數目
- minimum_largest範圍是 從單純"一個element"到"所有element累加";    
- 在此範圍的數值, 求出對應的segament; 判斷此segment是反滿足題意k

//=========

bool can_split_down(vector<int>& nums, int k, int sum){
  int cursum = 0;
  int cnt =1;//分割1次, 會有兩個分割區塊, 所以初始值要是1
  for(int i=0; i<nums.size(); i++){
    cursum +=nums[i];
    if(cursum>sum){
      cursum=nums[i];
      cnt++;
      if(cnt>k) return false;
    }
  }
  return true;//sum "s" can split array into  k partition.
}

int helper0(vector<int>& nums, int k){
  int l=0,r=0;
  for(int i=0; i<nums.size(); i++){
    l = max(l,nums[i]);//分成n份的minimum largest
    r +=nums[i];//分成一份的minimum largset
  }//分成一份 和 分成n份的 minimum largest

  while(l<r){
    int m = l + (r-l)/2;//first middle作為minimum_largest
    if(can_split_down(nums,k,m)) r = m;//可以繼續split_down,如果可以繼續split且分割後不超過k個
                                       // try much smaller value; 
    else l = m+1;//// try larger value; for decreasing  number of partition.
  }
  return r;
}

int splitArray(vector<int>& nums, int k) {
    return helper0(nums,k);
}
