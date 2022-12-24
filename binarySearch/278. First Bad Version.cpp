//====類似題===
279. Perfect Squares
1201. Ugly Number III
1918. Kth Smallest Subarray Sum
1482. Minimum Number of Days to Make m Bouquets

//===思路====
1.題目條件, 第一個出現bad之後, 接下來都是bad;如下圖, o=good, x=bad 
ooooooxxxxxxx...
      ^第一個出現bad的位址
  
.為什麼不用如下的描述?
while(l<=r)
if(<target)
else if(>target)
else//(==target)
  
-因為陣列中出現bad的個數,排列為如下形式; o=good, x=bad
ooooooxxxxxxxxx...
當出現一個bad, 則接下來都是bad.
  
-若用上面描述做題, 當第一次找到 bad時, 即跳出, 不會繼續往下找到第一個bad
-用以下描述 , l和r會不斷逼近, 逼近到l==r時跳出迴圈,此時得到的r為第一個出現bad的位置  
while(l<r)
if(<target)
else// >=target
  
  
//=======

int firstBadVersion(int n) {
    int l = 1, r = n;//nums.size()-1;
    while(l<r){
        int m = l+(r-l)/2;
        if(isBadVersion(m)){
            r=m;
        }else{//!isBadVersion()
            l=m+1;
        }
    }
    return r;
}
