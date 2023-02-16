//===類似題===
264. Ugly Number II
204. Count Primes
//===思路===
(*) 計算一個數是否可以整除 n ; 則
(x%n==0) , 對n取餘數等於零, 代表x有n的因數
//=======
bool helper0(int n){
     while(n>1){
        if(n%2==0){
            n/=2;
        }else if(n%3==0){
            n/=3;
        }else if(n%5==0){
            n/=5;
        }else {
            break;        
        }
    }
    return (n==1)? true: false; 
}
bool isUgly(int n) {
    return helper0(n);
}

