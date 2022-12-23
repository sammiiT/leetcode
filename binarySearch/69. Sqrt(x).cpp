//===類似題===
70. Climbing Stairs
380. Insert Delete GetRandom O(1)
2251. Number of Flowers in Full Bloom
1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
//===思路===
1. 每一次計算中間數的平方 並與 目標值(x)比較,
2. 用以下方法最後輸出會是lowerbounded
3. lowerbounded 所以求出的數值(r*r)有可能等於目標值, 也有可能大於目標值; 最後要做一個判斷.

(*)因為 0 <= x <= 2^31-1, 所以當x+1時會超出範圍, 所以一開始要做cast => (long)x
//=======
int mySqrt(int x){
  long l = 1, r = (long)x+1;
  while(l<r){//lower bounded
    long m = l+(r-l)/2;
    if(m*m<x)
    else//(m*m >= x)
      r = m;
  }
  return (r*r)>x?(r-1):r;
}

//======分析(l<=r)
int mySqrt(int x) {
    long l=1, r = x;
    while(l<=r){
        long m = l+(r-l)/2;
        if(m*m < x) l =m+1;
        else if(m*m >x) r = m-1;
        else return m;
    }
    return (r*r)>x?r-1:r;
}
