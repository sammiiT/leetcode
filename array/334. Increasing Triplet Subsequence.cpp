//=== 類似題 ===
1995. Count Special Quadruplets
2179. Count Good Triplets in an Array
2552. Count Increasing Quadruplets
//=== 思路 ===
Smallest and Smaller
1. 持續紀錄左邊出現的最小值與次小值，只要出現比這兩個值更大值，就代表找到
2. 這個方法的重點在於第二小的數目，當第二小的數目有被更新了(之前有出現比它小的數目)，我們就能確定只要大於它，就能找到三個漸增的數字
3. 當出現比原先最小還小的數字時，更新最小數字的目的是要讓第二小的數字有機會更新變得更小，增加找到漸增數字的機會
//===
bool increasingTriplet(vector<int>& nums) {
  int a = INT_MAX, b = INT_MAX;
  for(int n:nums){
      if(n<=a){
          a = n;
      }else if(n<=b){
          b = n;
      }else {//a<b<n
          return true;
      }
  }
  return false;
}
