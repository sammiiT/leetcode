//===類似題===
1654. Minimum Jumps to Reach Home
2124. Check if All A's Appears Before All B's
//===思路===
(*)從右到左遍歷數列, 每到一個位置[i], 即把數列分成兩部分[0:i],[(i+1):(n-1)]
-[(i+1):(n-1)] 中有多少個'a', 把'a'刪除 
-[0:i]中有多少個'b'; 把'b'刪除  
-(a+b)就是要被刪除的數量  

(*)每一次分割區段,都要計算一次 刪除數量的minimum
- res = min(res,(a+b));
  
1.遍歷一次, 記錄所有'a'出現的次數 total 
2.遍歷數列:如果[i]
-出現'a', 代表[(i+1):(n-1)]剩下 total-=1 個'a' 必須刪除
-出現'b', 代表[0:i]有 b++個 'b'; 

3. 算法如下:
a ababbab =>剩下3 a, b=0  => res=3 
aa babbab =>剩下2 a, b=0  => res=2
aab abbab =>剩下2 a, b=1  => res=3
aaba bbab =>剩下1 a, b=1  => res=2
aabab bab =>剩下1 a, b=2  => res=3
aababb ab =>剩下1 a, b=3  => res=4
aababba b =>剩下0 a, b=3  => res=3
aababbab  =>剩下0 a, b=4  => res=4

(*)i必須從(-1)開始,一開始刪除所有的'a', 留下'b'
s="b"; => answer = 0;

//=====
int minimumDeletions(string s) {
    int n = s.size();
    int res = INT_MAX;
    int a=0,b=0;
    for(char c:s) if(c=='a') ++a;

    for(int i=-1; i<n; ++i){
        if(i==-1) {}
        else if(s[i]=='a') --a;
        else ++b;
        res = min(res,a+b); 
    }
    return res;
}
//===思路====
用Dynamic Programming
