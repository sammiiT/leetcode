//===類似題===
8. String to Integer (atoi)
8. String to Integer (atoi)
2119. A Number After a Double Reversal
2442. Count Number of Distinct Integers After Reverse Operations
//===思路===
(*)range [-2^31, 2^31 - 1],所以做完reverse之後會有超出32bit邊界的風險
-在最後加上 (res>INT_MAX)||(res<INT_MIN)?0:res; 邊界判斷

-從最低位開始, 先求餘數, 當下的餘數會是下一次10進位的base
res = res*10+ x%10;
        \       \
         \       求餘數
        前一次餘數是下一次10進位的base 

-每一次計算都必須將數值除10
//=====
int reverse(int x) {
    long y = 0;
    for(;abs(x)>0;){
        y = y*10 + x%10;
        x/=10;
    }
    return (y>INT_MAX || y<INT_MIN)?0:y;
    //return y;        
}
//====
int helper0(int x){
    long i = x, j = 0;
    long div = 1;
    while(abs(x/div) >=10) div = div*10;
    while(div>0){
        j = j + (i%10)*div;//(i%10) 得到 + or -
        i = i/10;
        div = div/10;
    }
    return (j > INT_MAX || j < INT_MIN) ? 0 : j;//沒有此行會錯誤
//        return j;
}
int reverse(int x) {
    return helper0(x);
}
