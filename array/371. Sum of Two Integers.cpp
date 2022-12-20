//===類似題===
372. Super Pow
840. Magic Squares In Grid
1486. XOR Operation in an Array
2044. Count Number of Maximum Bitwise-OR Subsets
//===思路====


//====
 int helper0(int a, int b){
        while(b){
            int carry = (a & b & 0x7fffffff)<<1;//進位的解
            a = a^b;//計算後沒進位的解
            b = carry;
        }
        return a;
 }

 int helper1(int a, int b){
        if(b==0) return a;

        int carry = (a & b & 0x7fffffff)<<1;
        int sum = a^b;
        return helper1(sum,carry);

 }

 int getSum(int a, int b) {
//        return helper1(a,b);
        return helper0(a,b);
 }
