//===類似題===
172. Factorial Trailing Zeroes
2194. Cells in a Range on an Excel Sheet
//===思路====
(*)由題目可知,經轉換後的數字系統沒有"0"存在
1,2,3,4,5,6,7,8,9,10,11,~,26
A                         Z    

(*)如果有單獨"0"存在,則AA輸出會變成0
A=0 => AA = 0
  
1.從最低位算起,所以要從string的(n-1)算起  
//=====
int titleToNumber(string columnTitle) {
    int n = columnTitle.size();
    int res = 0;
    long tmp =1;//(int型態會overflow)
    for(int i=n; i>=1; i--){
      res = res + (columnTitle[i-1]-'A'+1)*tmp;
      tmp = tmp*26;
    }
/*  for(int i=n-1; i>=0; i--){
      res = res + (columnTitle[i]-'A'+1)*tmp;
      tmp = tmp*26;
    } */  
    return res;
}

//===思路2===
(*)從最高位算起, 每一次疊代,都要乘上26
//====
int helper(string s){
  int n = s.size();
  int res = 0;
  for(int i=0;i<n;i++){
      res = res *26 + (s[i]-'A'+1);
  }
  return res;
}

