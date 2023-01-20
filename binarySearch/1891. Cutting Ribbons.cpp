//===類似題===

//===思路===
(*)k = 分成k分
(*)k份的每一分數值, 是要最大; return 要分成k分索取的最大值
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


//====以下方式,沒辦法找到分割成1,1,1,1...的解
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
    }//最後l==r時,再判斷是否可以滿足題意
    return (split_count(nums,r)<k)? 0:r;
}

