//===類似題===
2295. Replace Elements in an Array
2564. Substring XOR Queries
1040. Moving Stones Until Consecutive II
1885. Count Pairs in Two Arrays

//===思路===
(*)sequence, 代表可以不用按照順序選取; 所以先對陣列作排列ascending
(*)最大與最小相差"最多K" 
- [最小,最大] 最多又(K+1)個, 每次取最多, 可以使partition數目最少
- 最少有0個


1.先作排列ascending
2.遍歷數列; 設定遍歷index i,j
-i是遍歷變數 index
-j是最小數的index

-如果[i]-[j]>k 則 partition+=1;
更新j;  j = i

-如果[i]-[j]<=k , 則continue;

(*)
-minimum number of subsequences
選越多array元素, 則得到越少的 subsequence

(*)最後的結果再加1,因為有可能發生sequence不會超過k的壯況

//===
int partitionArray(vector<int>& nums, int k) {
      int i,j,res=0,n = nums.size();
      sort(nums.begin(),nums.end());
      
      for(j=0,i=0; i<n; ++i){
          if(nums[i]-nums[j]>k){
              res+=1;
              j=i;
          }
      }  
      return res+1; //加1是考慮最後一個partition, 因為i==n時, 就跳出迴圈, 沒有計算到最後一個partition 
}
//===寫法2===
int partitionArray(vector<int>& nums, int k) {
    int res =0;
    int i,j;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    
    for(i=n-1,j=i; i>=0; --i){
        if(nums[j]-nums[i]<=k) continue;
        //nums[j]-nums[i]>k
        j=i;
        res +=1;
    }
    return res+1;
}

