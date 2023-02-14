//===類似題===
191. Number of 1 Bits
2119. A Number After a Double Reversal
//===思路===
1.for(int i=0; i<32; i++)
-位移32次,但第一次不會位移, 第一次是建立第0bit的數值
-第一次之後,第0bit才會往前位移, 因為有res<<1做疊代

(*)
res = res<<1 +(n & 0x01);//會有錯誤
=> compiler會將此式子翻譯為 res = res<< (1+(n&0x01));
所以要將此式描述為:
res = (res<<1) + (n & 0x01);
//=====
uint32_t reverseBits(uint32_t n) {
    uint32_t res=0;
    for(int i=0;i<32;i++){
        res = res<<1; 
        res = res + (n & 0x01);
//        res = res<<1 +(n & 0x01);//會有錯誤??? 為什麼
        n=n>>1;        
    }
    return res;  
}
//===failed===
錯誤概念:不能用while迴圈
uint32_t reverseBits(uint32_t n) {
    uint32_t res=0;
//用while判斷是否為零會錯誤, 000000000000000000001,反轉之後,會變成1
//沒有接下來的0將1往前推
    while(n){
        res = res<<1; 
        res = res + (n & 0x01);
        n=n>>1;//        
    }
    return res;  
}
