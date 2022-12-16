//===類似題===
358. Rearrange String k Distance Apart
2376. Count Special Integers

//===思路===
(*)找出關係, 化為關係式, 實作關係式
1. 關係
n=1,[0~9]   ; unique = 10
n=2,[10~99] ; unique = 81
n=3,[100,999]; ....
  
f(1)=10
f(2)=9*9       (9-2+2) =9 
f(3)=9*9*8     (9-3+2) =8 
f(4)=9*9*8*7   (9-4+2) =7     
          
2.n=0不在上述的公式條件下,所以要獨立討論
  n=1不在上述的公式條件下,所以要獨立討論
//=======
/*
計算區間
k=1 (1位)=> [0~9]  
k=2 (2位)=> [10~99]
k=3 (3位)=> [100~999]
...
*/
int count(int k){//計算區間裡, unique digits個數
  int res = 1;
  if(k<1) return 0; 
  if(k==1) return 10;//10個unique digits
  
  for(int i=9; i<(9-k+2); --i){
    res*=i;
  }
  return res*9;
}

int helper0(int k){
  int res = 0;
  if(n==0) return 1;
  for(int i=1; i<k; i++){
    res+=count(i);
  }
  return res;
}
