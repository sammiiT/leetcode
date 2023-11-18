//===類似題===
204. Count Primes
2787. Ways to Express an Integer as Sum of Powers

//===思路===
(*) 動態規劃 dp[i]
1.數值n, 每一個element的初始值為1, 表示每一個數值可形成的完全平方數有一個

2.因為累加, 因為用1來做累加
n = 13
dp[1]=1
dp[2]=dp[1] + 1= 1+1=2
dp[3]=dp[2] + 1= 2+1=3
dp[4]=dp[3] + 1= 3+1=4
                 
dp[13-1] = min(dp[13],dp[12]+1) =  
dp[13-4] = min(dp[13],dp[9]+1)  = 
dp[13-9] = min(dp[13],dp[4]+1)  = 

  
(*)+1的目的 是 另一個 完全平方數???
- dp[13-9] =dp[4]+1 ; +1 就是單獨 4完全平方數個數         
- dp[13-4] =dp[9]+1 ; +1 就是單獨 9完全平方數的個數 
                              

n = 12
dp[12-1] = min(dp[12],dp[11]+1)
dp[12-4] = min(dp[12],dp[8]+1)
dp[12-9] = min(dp[12],dp[3]+1)
                    
-----------
int numSquares(int n) {
    vector<int> dp(n+1,1);

    for(int i=0; i<=n; ++i){
        dp[i]=i;
        for(int j=1; i>=j*j ; ++j){
            dp[i]=min(dp[i], dp[i-j*j]+1);
        }
    }
    return dp[n];
}
