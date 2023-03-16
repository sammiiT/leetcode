//===類似題===
2105. Watering Plants II
907. Sum of Subarray Minimums
1944. Number of Visible People in a Queue
1759. Count Number of Homogenous Substrings
//===思路====
(*)雙loop求解, i和j的區間就是一個subarray
(*)每一次先固定i, 變動j, 每一次的區間都可以判斷出當下subarray的min和max
- lo = min(lo,nums[j]); hi = max(hi,nums[j]);
-利用max和min值來求算每一subarray的range

(*)雙迴圈遍歷完,即為解
//=====

long long subArrayRanges(vector<int>& nums) {
  int n = nums.size();
  long long res = 0;
  for(int i=0; i<n; i++){
    int lo = nums[i];
    int hi = nums[i];
    for(int j=i+1; j<n; j++){
      lo = min(lo,nums[j]);
      hi = max(hi,nums[i]);
      res = res + (hi-lo);
    }
  }
  return res;
}
