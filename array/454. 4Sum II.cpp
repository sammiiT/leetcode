//===類似題====
455. Assign Cookies
1834. Single-Threaded CPU
977. Squares of a Sorted Array
2251. Number of Flowers in Full Bloom

//===思路===
(*)利用unordered_map
1.將四個陣列,倆倆一對
2.A,B一組, 計算所有和的可能,結果存入map中
3.計算剩下C,D的和, 其結果是否存在於map中
- 根據題意;所有的和必需等於0,所以 (C+D)*(-1)必須存在於map中
//====
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
  unordered_map<int,int> m;//A+B, count
  for(int i=0;i<A.size();i++){
    for(int j=0;j<B.size();j++){
      m[A[i]+B[j]]++;
    }
  }
  for(int i=0; i<C.size(); i++){
    for(int j=0;j<D.size();j++){
      int target = (-1)*(C[i]+D[j]);
      res = res +m[target];
    }
  }
  return res;
}
