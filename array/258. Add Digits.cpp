//===類似題===
259. 3Sum Smaller
1085. Sum of Digits in the Minimum Number
1945. Sum of Digits of String After Convert
2160. Minimum Sum of Four Digit Number After Splitting Digits

//===思路====
1.用string來做運算
2.用取10餘數, 取10商數 做運算

//======
 int helper0(int num){//string運算
  string s = to_string(num);
  int res = num;
        
  while(s.size()>1){
    int n = s.size();
    res = 0;
    for(int i=0;i<n;i++){
      res+=(s[i]-'0');
    }
    if(res<10) break;
    s = to_string(res);
  }
  return res;
 }

int helper1(int num){//取餘數,商數
    int n = num; 
    while(n>=10){
        int res = 0;
        while(n>0){
            res+=n%10;
            n/=10;
        }
        n = res;
    }
    return n;
}

int addDigits(int num) {
        return helper0(num);
 }

//===寫法2===
int addDigits(int num) {
    unsigned int tmp = 0;
    while(num/10){
        int val = num;
        while(val){
            tmp = tmp + val%10;
            val = val/10;    
        }
        num = tmp;
        tmp = 0;
    }
    return num;
}
