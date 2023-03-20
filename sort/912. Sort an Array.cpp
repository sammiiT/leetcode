//===類似題====
913. Cat and Mouse
2559. Count Vowel Strings in Ranges
1774. Closest Dessert Cost
2215. Find the Difference of Two Arrays

//===思路=====
(*)用quick sort會出錯, 因為其worst case是O(n^2), 導致time limited exceeded
(*)用count sort; 其時間複雜度是O(n); 要用到座標轉換
(*)用heap sort, 其時間複雜度是O(nlogn)

//=======
/* count sort*/
vector<int> sortArray(vector<int>& nums){
    int n = nums.size();
    vector<int> count(100001,0);//-50000變成0, count的index 就是出現的數值; 所以 -1~-50000, 1~50000, 0 一共100001個數字
    vector<int> res(n);          //所以不能只宣告size=50000
    int j = 0;
    for(int a: nums) ++count[a+50000];
    for(int i=0;i<count.size();++i){
        while(count[i]-->0){
            res[j++]=i-50000;
        }
    }
    return res;
}

/* heap sort */
vector<int> sortArray(vector<int>& nums){
  priority_queue<int> q(begin(nums),end(nums));
  int i = nums.size();
  //while(i>=0){//此描述錯誤,會造成q.empty()時,還對queue取數值的情況
  //while(!q.empty()){
  while(i>0){
    nums[--i] = q.top();
    q.pop();
  }
  return nums;
}
