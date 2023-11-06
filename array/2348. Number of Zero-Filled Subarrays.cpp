//===類似題===
2347. Best Poker Hand
413. Arithmetic Slices
2110. Number of Smooth Descent Periods of a Stock
2414. Length of the Longest Alphabetical Continuous Substring

//===思路1====
(*)雙指針, 一個指針紀錄頭, 一個指針紀錄尾

(*)
- 0的start位置
- 0的end位置
- 如何判斷連續0發生的subarray

//====
long long subarray_count(long long n){
    long long res = 0;
    //for(int i=1;i<=n;i++) { res+=(n+1-i); }//res+=i;//
    res = (1+n)*n/2;
    return res;
}
long long zeroFilledSubarray(vector<int>& nums) {
    int n = nums.size();
    long long j=0,pre=-1,res=0;
    
    for(int i=0; i<n; ++i){
        if(nums[i]==0 && pre == -1) {//0 的start位置
            j = pre = i;
            continue;
        }
        if(nums[i]==0 && pre ==(i-1)) {//判斷連續0發生的subarray 
            pre = i;
            continue;
        }
        if(pre!=-1){ res += subarray_count(pre-j+1); }//0的end位置, 計算連續0的subarray長度
        pre = -1;
    }
    if(nums[n-1]==0){ res+=subarray_count(pre-j+1); }//邊界條件, 最後一個區塊因為超出index (n-1),所以要再做一次判斷
    return res;
}

//===思路2===
long long zeroFilledSubarray(vector<int>& nums) {
  int res=0,cnt=0;
  for(int a:nums){
      if(a==0){
          cnt++;
          res+=cnt;
      }else{
          cnt=0;
      }
  }
  return res;
}

//===寫法3====
long long zeroFilledSubarray(vector<int>& nums) {
    long long count = 0;
    long long res = 0;
    int n = nums.size();

    for(int j=0; j<n; ++j){
        if(nums[j]){
            res = res +  ((count>0)?(1+count)*count/2:0);//total;
            count=0;
        }else{//nums[j]=0
            count++;
        }
    }
    if(count) res = res + (1+count)*count/2;
    return res;
}

