//===類似題===
44. Wildcard Matching
2288. Apply Discount to Prices

//===思路===
(*)會有超過integer bit數的可能, 所以不能用stoi

1.宣告一陣列,此陣列記錄每一次,每一位相乘疊加後的結果
- 1位 乘1位 ,最大是2位, 所以陣列大小為num1.size()+num2.size()+1

2.從最大的index開始算, 算回index=0;雙迴圈計算
    9    => index 0 
  3 9    => index 0,1
-------
  8 1
2 7
  
一開始, [0]*[1] =>會占用陣列的[1,2]位  
第二次, [0]*[0] =>會占用陣列的[0,1]位,所以相乘後的結果要先加上前一次的[1]數值 
...
以此類推填滿整個陣列就是最後的解

//=====
string multiply(string num1, string num2) {
  int m = num1.size(), n = num2.size();
  vector<int> t(m+n,0);
  string res;
  
  for(int i=m-1; i>=0; i--){
    for(int j=n-1; j>=0; j--){
      int mul = (num1[i]-'0')*(num2[j]-'0');
      int p1 = i+j, p2=i+j+1;
      int sum = mul+ t[p2];
      t[p2]=sum%10;
      t[p1]=t[p1] + sum/10;
    }
  }
  for(int a:t){
      //如果第一個數是0
      if(!res.size() && a==0) continue;
      res.push_back(a+'0');
//    if(!res.empty()||a!=0) res.push_back(a+'0');      
      
  }
  return res.empty()?"0":res; 
  
}

