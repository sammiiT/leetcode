//===類似題===
396. Rotate Function
2014. Longest Subsequence Repeated k Times
2067. Number of Equal Count Substrings
2405. Optimal Partition of String

//===思路===
(*)遇到substring題目, 就要一個一個比較來計算個數
每一個情況都要考慮,所以會用到雙迴圈判斷所有可能性


    i     j
 o  o  o  o  o  o


1.設定一mask,定義此substring是否滿足提議條件"每個字母都至少k個"
- 如果字母少於k個, mask 對應的bit設定為1
- 如果字母大於等於k個,mask對應的bit設定為0

2.如果mask等於0,代表此substring滿足題意,每一個字母的個數都大於等於k個
3.每次計算出substring滿足題意, 就要更新一次邊界值,此邊界值是給下一個i做基準
//=======

int longestSubstring(string s, int k) {
  int res=0, n = s.size(), max_start=0, i=0;
  while(i+k<=n){
      int m[26]={0}, max_start = i, mask=0;
    
      for(int j=i; j<n; j++){
          int t = s[j]-'a';
          m[t]++;
          if(m[t]<k) mask = mask | (1<<t);
          else{// >=k
              mask = mask & ~(1<<t);
          }
          if(mask==0){
              res = max(res,j-i+1);
              max_start = j;
          }
      }
      i=max_start+1;
  }
  return res;
}
