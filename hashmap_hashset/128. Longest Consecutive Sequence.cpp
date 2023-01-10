//===類似題===
129. Sum Root to Leaf Numbers
298. Binary Tree Longest Consecutive Sequence
2177. Find Three Consecutive Integers That Sum to a Given Number
2274. Maximum Consecutive Floors Without Special Floors

//===思路===
(*)hashset做運算
1. 將陣列元素放入set中
2. 遍歷 set, 如果出現在set中, 先將set值移除,防止重複計算
3. 定義數值的左,右邊
4. 持續往左側找, 持續往右側找 
5. right-left-1 , 減1是因為,最後right和left都停在set不存在的數值上, 如果要算存在的數值,要再多減1
  left        right
   x o o o o x  
   
 x表示不存在, right-left-1, 把right自己減掉  
   
6.每次比較 consecutive的最大值
//======
int helper0(vector<int>& nums){
  int res = 0;
  unordered_set<int> s(nums.begin(),nums.end());
  for(int a:nums){
    if(!s.count(a)) continue;
    s.earse(a);
    int left = a-1, right = a+1;
    
    while(s.count(left)) s.erase(left--);
    while(s.count(right)) s.erase(right++);
    res = max(res,right-left-1);
  }
  return re;
}

int longestConsecutive(vector<int>& nums){
  return helper0(nums);
}

//====思路2===


//=====
int helper0(vector<int>& nums) {
        int res = 1;
        int count = 1;
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());//先排序
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==(nums[i-1]+1)) {
                count++;
                res = max(count,res);
            }else if(nums[i]==nums[i-1]){
            }else{
                count=1;//中間consecutive斷掉, 重新計算
            }
        }
        return res;
}

