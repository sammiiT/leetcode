//===類似題===
327. Count of Range Sum
1780. Check if Number is a Sum of Powers of Three
//===思路===

//======
bool isPowerOfThree(int n) {
    while(n>1){
        if(n%3==0) n/=3;
        else return false;
    }
    return (n==1);
}
