//===類似題===

//===思路===
1.取k
2.考慮反饋
ex1:三個數
1,2,3
直接猜2, 因為根據回饋, 會得知下一次是1或3, 當取到正確的數值, 不會有cost
所以三個數, 最少cost就是取中間數


ex2:四個數
1,2,3,4

猜1; 左區間沒數字, cost 0, 右區間直接選中間位置,cost 3 是最低的開銷; 所以 左區間+猜1+右區間=0+1+3=4 
                                                                            => local_max=k+max(dp[j][k-1],dp[k+1][i]), maximum 是3
                                                                            
猜2; 左區間1(只有一個數字,經反饋在猜 cost 0); 右區間3,4直接選最小的 cost 3; 所以 左區間+ 猜2+右區間 = 0+2+3=5
                                                                            => local_max=k+max(dp[j][k-1],dp[k+1][i]), maximum 是3
                                                                            
猜3; 左區間1,2,直接選最小的數值1; 右區間只有一個數字,經反饋一定猜對,所以cost 0; 所以 左區間+猜3+右區間 1+3+0 =4
                                                                            => local_max=k+max(dp[j][k-1],dp[k+1][i]), maximum 是1

猜4; 左區間1,2,3,猜2因此 cost 2; 左區間沒有數值, 所以cost 0; 所以 左區間 + 猜4+ 右區間 = 2+4+0 = 6
                                                                => local_max=k+max(dp[j][k-1],dp[k+1][i]), maximum 是 2      

(*)所以 4,5,4,6 最小是 4  => global_min = min(global_min,local_max)




int getMoneyAmount(int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));    
    for(int i=2; i<=n; ++i){//1,2  end從2
        for(int j=i-1; j>0; --j){// start 從(end-1)開始
            int global_min = INT_MAX;
            
            for(int k=j+1; k<i; ++k){
                int local_max = k + max(dp[j][k-1],dp[k+1][i]);  
                global_min = min(global_min, local_max);
            }
            
            dp[j][i] =  j + 1==i?j:global_min;
//          dp[j][i] = (j + 1)==i?j:global_min;            
        }
    }
    return dp[1][n];
}
