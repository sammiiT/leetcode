//===類似題===

//===思路===
(*)k = 分成k分
(*)k份的每一分數值, 是要最大; return 要分成k分索取的最大值

(*)概念, 與 410. Split Array Largest Sum
- 以數值, minimum_largest 來求出 對應的segement數目
- minimum_largest範圍是 從單純"一個element"到"所有element累加";    
- 在此範圍的數值, 求出對應的segament; 判斷此segment是反滿足題意k

此題目:
- 以數值, 來求出條件所需的 segament數目
-此數值的範圍, 從數列中的最小值來定義 [1: minimum_element_value]
- 先定義 length大小, 求出對應的segement; 判斷此segement是否滿足題意 k 

    
//======
int split_count(vector<int>& nums,int m){
    int res = 0;
    for(int i=0;i<nums.size();i++){
        res+=(nums[i]/m);        
    }
    return res;//count
}

int helper0(vector<int>& nums, int k){
  int l,r;
  sort(nums.begin(),nums.end());
  l=1,r = nums[0];
  while(l<r){
      int m = l +(r-l+1)/2;//用second middle =>這樣就可以必免 l=m 無法跳到最後一個元素上的問題
      if(split_count(nums,m)>=k) l = m;//有等於符號的, 更新的值就是只有m,不用+1或-1, 但在l取解會有跳不出迴圈的問題(必須用second middle才能避免此問題)
      else // < k
          r = m-1;
  }
  return (split_count(nums,r)<k)?0:r;
}


int helper1(vector<int>& nums, int k){
  int l=1,r=0;
  //sort(nums.begin(),nums.end());
  for(auto num,nums) r = max(r,num);
  
  while(l<r){//l<=r 當(l==r)時,會跳不出迴圈, 要用一個判斷式跳出迴圈 
      int m = l +(r-l+1)/2;//用second middle =>這樣就可以必免 l=m 無法跳到最後一個元素上的問題
      if(split_count(nums,m)>=k) l = m;//有等於符號的, 更新的值就是只有m,不用+1或-1, 但在l取解會有跳不出迴圈的問題(必須用second middle才能避免此問題)
      else // < k
          r = m-1;
  }
  return (split_count(nums,r)<k)?0:r;
}
//====思路=========
(*)長度會反映切割的segment數目
(*)robbin中,長度最短的作為右極限 r = minimum_robbin
(*)左極限 l=1, 右極限 r=minimum_robbin 作為binary search的運算元素; 遞增特性
(*)每取到一段長度 經運算, 可以得到總segment數目
- segment 越多, 代表長度要變長, 所以往長度長的方向移動 l=m+1
- segment 越少, 代表長度要變短, 所以往長度短的方向移動 r = m;
    
int seg_count(vector<int> nums,int length){
    int res = 0;
    for(int num:nums)
        res+=res/length;
    return res;    
}

int helper0(vector<int>& nums, int k){
    int l = 1, r =INT_MAX;//  minimum length to maximum length
    for(auto num:nums) r = min(r,num);//找到最小長度的那一個robbin
     
    while(l<r){
        int m = l+(r-l)/2;
        //length + , k -
        if(seg_count(nums,m) > k) //segment越多, 代表長度要變長,所以往長度長的方向移動  
            l=m+1;//length變長, segment就變少
        else //seg_count(nums,k) <= k ; segment越少,代表長度要變少, 所以往長度短的地方移動
            r = m;//length截短, segment就會變多
    } 
    //return r;
    return seg_count(nums,r)<k?0:r;
}

//====以下方式,沒辦法找到分割成1,1,1,1...的解....???===> 運算是可以找到
int helper0(vector<int>& nums, int k){
    int l,r;
    sort(nums.begin(),nums.end());
    l=1,r = nums[0]; //l不可以等於0
    while(l<r){
        int m = l+(r-l)/2;//用數值算, 求出的middle是first middle
        if(split_count(nums,m)<=k){//得到的count數比k少, 表示要取比m更小的數 =>所以r要往m方向移,才會取到更小的值
            r = m;//r=m; 把等於放在r==m的地方
        }else{//split_count(nums,m)>k
            l = m+1;
        }
    }
    //最後l==r時,再判斷是否可以滿足題意; 是否等於k
    return (split_count(nums,r)<k)? 0:r;

//如果單純 return r;//會出錯
    
}
//--將上面helper0做修改, 可以判斷到 分割成1,1,1,1...的解
/*
int helper0(vector<int>& nums, int k){
    int l=1, r=*min_element(ribbons.begin(),ribbons.end());//找到最小的ribbon,此長度必須小於等於k
    if(r<k) return 0;
    
    while(l<r){
        int m = l+(r-l)/2;
        int cnts = split_count(nums,m);
        if(cnts<=k){
            r = m;
        }else{//cnts>k
            l = m+1;
        }
    }
    return r;//此時的r是否滿足 使ribbon產生k段??? 所以必須再計算一次
}*/
