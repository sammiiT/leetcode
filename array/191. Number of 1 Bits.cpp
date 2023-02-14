//===類似題===
198. House Robber
338. Counting Bits
401. Binary Watch
461. Hamming Distance
//===思路===
(*)不能用以下描述
while(i){
    res++;//如果當下那一個bit是,res又會加上一次,所以不能這樣算
    i = i>>1;
}
//=====
int hammingWeight(uint32_t n) {
    uint32_t i = n;
    long res = 0;
    while(i){
        res = res + (i&0x01);
        i=i>>1;    
    }
    return res;
}
