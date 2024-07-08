//===類似題===
265. Paint House II
204. Count Primes
279. Perfect Squares
313. Super Ugly Number

//===思路====
(*)每一個陣列的元素, 都只有2,3,5因數的累計,所以在計算的過程中取最小的那一個
(*)由前面的元素再乘上2,3,5;比較每一個數的大小, 最小值才能被加入陣列
(*)有dynamic programming的味道

2,3,5的陣列有各自的index, 從0開始, 如果對應index數值乘上2,3,5是最小值, 那就把此最小值放到陣列中
陣列前面的每一個元素, 都僅有2,3,5的乘積; 一直乘下去, 乘到第n個

(*)
2的倍數是最小; 基底如何找? 基底index, 對應之前算出的數值 
3的倍數是最小; 基底如何找? 基底index, 對應之前算出的數值
5的倍數是最小; 基底如何找? 基底index, 對應之前算出的數值

i2=0 2倍數一開始的基底index    
i3=0 3倍數一開始的基底index    
i5=0 5倍數一開始的基底index

//=====
int helper0(int n){
  vector<int> res(1,1);//第一個數為1,也被視為ugly number
  int i2=0,i3=0,i5=0;
  while(res.size()<n){//第n個,表示要執行n次, res.size()初始值為1,所以只要執行n-1次
                      //res.size()=1, index=1開始  1,2,3,4,5,6,7,8,9 <10 共9次, 加上原來res.size()=1的那一個, 共10個數
    int m2=res[i2]*2, m3=res[i3]*3, m5=[i5]*5;
    int mn = min(m2,min(m3,m5));
    if(mn==m2) i2++;
    if(mn==m3) i3++;
    if(mn==m5) i5++;
    res.push_back(val);
  }
  return res.back();
}

int nthUglyNumber(int n) {
    return helper0(n);
}

//===思路2====
(*)利用priority_queue
(*)每次 top()的數值都提出, 並乘上2,3,5, 再push()回priority_queue中
(*)priority_queue 的top(),是否會與接下來的一個數值相同, 若相同則pop()出, 直到沒有重複為止
(*) 執行最後 回傳top(), 即為解

int nthUglyNumber(int n) {
    priority_queue<long,vector<long>,greater<long>> pq;
    pq.push(1);

    for(int i=1; i<n; ++i){
        long val=pq.top();pq.pop();
        while(!pq.empty() && val==pq.top()){
          val = pq.top();pq.pop();
        }
        pq.push(val*2);
        pq.push(val*3);
        pq.push(val*5);
    }
    return pq.top();
}

