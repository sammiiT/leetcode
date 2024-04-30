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
