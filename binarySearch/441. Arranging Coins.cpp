//===類似題===
442. Find All Duplicates in an Array
1214. Two Sum BSTs
2563. Count the Number of Fair Pairs
458. Poor Pigs
//===思路===
(*)用binary search(lower bound算法)
(*)最後算出來的結果是lower_bound,所以還要再算一次是否符合題意
//=====
int helper0(int n) {
    long l = 1, r = n;
    if(n<=1) return n;
    while(l<r){
        long m = l+(r-l)/2;
        if(m*(m+1)/2<n) l = m+1;
        else//(m*(m+1)/2)>=target
            r = m;
    }
    return (r*(r+1)/2>n)?(r-1):r;//最後算出來的結果是lower_bound,所以還要再算一次是否符合題意
}

int arrangeCoins(int n) {
    return helper0(n);
}
