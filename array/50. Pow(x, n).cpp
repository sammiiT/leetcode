//===類似題===
51. N-Queens
372. Super Pow
2550. Count Collisions of Monkeys on a Polygon
//===思路===
1.若依照次方個數一次做運算會發生Time Limit Exceeded
2.用log(n)方式, 每一次除以2來計算相乘次數
3. 利用DFS,從最小的次方開始計算起, 再往上層運算; 將下層的數往上層做運算 

ex:
第0層:  10                                   ((2*2)*(2*2)*2)*((2*2)*(2*2)*2)         
                                                  |
第一層: 10/2 = 5                   (2*2)*(2*2)*2 -/
                                           | 
第二層: 10/2/2 = 2    (1*1*2)*(1*1*2)=2*2 -/ 
                               | 
第三層: 10/2/2/2 = 1    1*1*2 -/
                         |
第四層: 10/2/2/2/2 = 0  -/    

//====
double myPow(double x, int n){
  if(n==0) return 1;
  
  double half = myPow(x,n/2);
  if(n%2==0) return half*half;//偶數
  if(n>0) return half*half*x;//奇數(+);要避開 n<0的情況 ; 奇數個所以平方後, 再多乘一個x
  return half*half/x;//奇數(-)
                     //half從上層傳上來已經是"分數"狀態  
}
//===計算n幾次方====
if(n=0) return 1;//除2等於0,表示被除數是1或0=> 假設是1

int half = myPow(x,n/2);
if(n%2==0) return half*2;
if(n%2==1) return (half+1);


//===failed ====
AddressSanitizer:DEADLYSIGNAL
=================================================================
==31==ERROR: AddressSanitizer: stack-overflow on address 0x7ffc52cb3ff8 (pc 0x000000343a6f bp 0x7ffc52cb4010 sp 0x7ffc52cb4000 T0)
==31==ABORTING
Last Executed Input
0.00001
2147483647

double helper(double x, int n){
    if(n==0) return 1;
    double res = 0;
    res = helper(x,n-1);
    res = res*x;
    return res;
}


