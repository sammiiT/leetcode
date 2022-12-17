//===類似題===

//===思路===
1.若依照次方個數一次做運算會發生Time Limit Exceeded
2.用log(n)方式, 每一次除以2來計算相乘次數
3. 利用DFS,從最小的次方開始計算起, 再往上層運算; 將下層的數往上層做運算 


//====
double myPow(double x, int n){
  if(n==0) return 1;
  
  double half = myPow(x,n/2);
  if(n%2==0) return half*half;
  if(n>0) return half*half*x;//要避開 n<0的情況 ; 奇數個所以平方後, 再多乘一個x
  return half*half/x;
}


//===計算n幾次方====
if(n=0) return 1;//除2等於0,表示被除數是1或0=> 假設是1

int half = myPow(x,n/2);
if(n%2==0) return half*2;
if(n%2==1) return (half+1);
