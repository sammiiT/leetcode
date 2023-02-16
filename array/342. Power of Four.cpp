//===類似題===
343. Integer Break
326. Power of Three
//===思路====
(*)判斷x是否為 n的倍數
(x%n==0)取餘數等於0, 代表n為x的因數; x為n的倍數
//====
bool isPowerOfFour(int n) {
    while(n>1){
        if(n%4==0) n/=4;
        else return false;
    }
    return (n==1);
}
