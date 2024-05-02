//===
(*)DFS
 int knapsack(int W,
            vector<int>& wt, 
            vector<int>& val, 
            int n){
    if(n==0||W==0) return 0;
    if(wt[n-1]>W) return knapsnak(W,wt,val,n-1);
    return  max(knapsack(W-wt[n-1],wt,val,n-1)+val[n-1],
                        knapsack(W,wt,val,n-1));
             
} 

//===
(*)DFS + memory
int knapsack(int W,
            vector<int>& wt, 
            vector<int>& val, 
            int n,
            vector<vector<int>>& memo){
    if(W<0) return -1e9;
    if(n==0) return 0;
    if(memo[n][W]) return memo[n][W];
    
    return memo[n][W] = max(knapsack(W-wt[n-1],wt,val,n-1,memo)+val[n-1],
                        knapsack(W,wt,val,n-1,memo));
             
}

int main(){
    vector<int> profit = {60,100,120};
    vector<int> weight = {10,20,30};
    
    int W = 50;
    int n = profit.size();
    vector<vector<int>> memo(n+1,vector<int>(W+1,0));
    
    cout<<knapsack(W,weight,profit,n,memo)<<endl;
    return 0;
}

//=====


int knapsack(int W, 
            vector<int>& wt, 
            vector<int>& val, 
            int index,
            int** dp){
    if(index < 0) return 0;
    if(dp[index][W]!=-1) return dp[index][W];
    
    if(wt[index] > W) {
        return dp[index][W] = knapsack(W,wt,val,index-1,dp);
    }
    
    dp[index][W] = max(knapsack(W-wt[index], wt, val, index-1,dp)+val[index],
                        knapsack(W,wt,val,index-1,dp));
    return dp[index][W];
}

//===dynamic programming ===
(*) dynamic programming的(n+1)目的是為了,在運算式中,可以計算到前一個數值
- 下一個數值跟前一個數值有關 , 所以dp的大咬會比原陣列多1個元素

int knapsack(int W, vector<int>& wt, vector<int>& val, int n){
    int i,w;
    vector<vector<int>> k(n+1,vector<int>(W+1));
    
    for(int i=0; i<=n; ++i){
        for(w=0; w<=W; ++w){
            if(i==0||w==0){
                k[i][w]=0;
            } else if (wt[i-1]<=w){
                k[i][w] =  max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            } else {
                k[i][w]=k[i-1][w];
            }
        }
    }
    return k[n][w];
}

//[i] = [i-1] ;第1個是第(1-1)個的結果 
//第三個是第二個計算的結果 => 但第三個
//第三個 + 

/*
(*) dynamic programming的(n+1)目的是為了,在運算式中,可以計算到前一個數值
- 下一個數值跟前一個數值有關 , 所以dp的大咬會比原陣列多1個元素ad

第2個的運算結果(包含第2個的條件) = 第3個
                                 = 第四個=第3個的運算結果(包含第3ad個的條件)
*/

/*==== coin problem ===
是unbounded knapsack problem的變形


knapsack(W-wt[n-1],wt,val,n)// 1
knapsack(W,wt,val,n-1)//0

vector<int>& wt;//面額


bool change(int W,          //能否湊出 W 
            vector<int>& wt,//面額
            int n){         //面額總數

    if(n<0 || W<0) return 0;
    if(W == 0) return true;
    
    if(c[n][W]!=-1) return c[n][W];
    
    return c[n][W] = change(W-wt[n-1],wt,n)|| change(W,wt,n-1);
    
    
    
}
