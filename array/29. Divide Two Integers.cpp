//====類似題=====
30. Substring with Concatenation of All Words
2005. Subtree Removal Game with Fibonacci Tree
313. Super Ugly Number
2177. Find Three Consecutive Integers That Sum to a Given Number

//====思路====
1. INT_MIN/(-1) 會超過 INT_MAX; 所以要將這個條件避開
2. 利用2倍除數來做運算
3. 如果用加法來實作會發生 Time Limit Exceeded
4. 計算相乘後的正負號 可用xor來避免 相乘超過 整數形態上下限
int sign = (dividend<0)^(divisor<0)?-1:1;

//=====
int helper0(int dividend, int divisor){
        int res = 0;
        int sign = (dividend<0)^(divisor<0)?-1:1;
        long m = labs(dividend), n = labs(divisor);

        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(n==1) return (sign<0)?-m:m;
                
        while(m>=n){
           long t = n;//2倍數的基底
           long p = 1;//紀錄每次次數     
           while(m>=(t<<1)){//判斷每次是否能以兩倍除數做運算
               t=t<<1;//2倍除數
               p=p<<1;//當下的次數, 因為是2倍除數, 所以當作除2次
           }
           res = res+p;//總次數
           m = m-t;//每一次的餘數 
        }
        return (sign<0)?-res:res;
}

int divide(int dividend, int divisor) {
        return helper0(dividend,divisor);       
}
