//===類似題===
65. Valid Number
174. Dungeon Game
741. Cherry Pickup
2304. Minimum Path Cost in a Grid

//===思路===
(*)dynamic programming算法
(*)不用in-place; 新增一dp的matrix儲存每一個點的結果
1.初始化邊界
 1 | 3 | 1          1 | 4 | 5
---+---+---    =>  ---+---+---      
 1 | 5 | 1          2 |   | 
---+---+---        ---+---+---
 4 | 2 | 1          6 |   |
 
2.方程式 dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[j][j-1])    
      
//===
int helper(vector<vector<int>>& grid){
    int m = grid.size(),n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    
    dp[0][0]=grid[0][0];
    for(int i=1;i<m;i++) dp[i][0]=dp[i-1][0]+grid[i][0];
    for(int i=1;i<n;i++) dp[0][i]=dp[0][i-1]+grid[0][i];
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

//===failed===
不能用下面方式, 因為沒有真正初始化"邊界"
 0 | 0 | 0 | 0          0 | 0 | 0 | 0
---+---+---+---        ---+---+---+---  
 0 | 1 | 3 | 1          0 | 1 | 3 | 1  
---+---+---+---    =>  ---+---+---+---      
 0 | 1 | 5 | 1          0 | 1 |   |   
---+---+---+---        ---+---+---+---
 0 | 4 | 2 | 1          0 | 4 |   |   
-邊界還是一樣,所以計算會錯誤    

int helper0(vector<vector<int>>& grid){
    int m = grid.size()+1,n = grid[0].size()+1;
    vector<vector<int>> dp(m,vector<int>(n,0));

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=grid[i-1][j-1]+ min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp.back().back();//dp[m-1][n-1];
}
(*)修正寫法: 即可解決上述錯誤
- 邊界的初始化, 在dp update中執行
if((i-1)==0) 
  dp[i][j] = dp[i-1][j] + grid[i-1][j-1];//不看"j", 只update "i"
else if((j-1==0)) 
  dp[i][j] = dp[i][j-1] + grid[i-1][j-1];//不看"i", 只update "j"
-----

int helper1(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if((i-1)==0) 
                dp[i][j] = dp[i-1][j] + grid[i-1][j-1];
            else if((j-1==0)) 
                dp[i][j] = dp[i][j-1] + grid[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
        }
    }
    return dp[m][n];
}




//===思路2====
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0||n==0) return 0;
        
        vector<vector<long>> dp(m,vector<long>(n,0));
        
        //initial
        // for(int j=0; j<n; ++j){ dp[0][j]=grid[0][j];}
        // for(int i=0; i<m; ++i){ dp[i][0]=grid[i][0];}
        
        // for(int j=0; j<n; ++j){ 
        //     dp[0][j]=dp[0][j]+grid[0][j];
        // }
        // for(int i=0; i<m; ++i){ 
        //     dp[i][0]=dp[i][0]+grid[i][0];
        // }
        
        dp[0][0]=grid[0][0];
        for(int j=1; j<n; ++j){ 
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=1; i<m; ++i){ 
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                // dp[i][j]=dp[i-1][j-1] + min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1];
        // return 1;
    }
//(1)用遞迴, return min(path_a,path_b); 
/*


if(i==(m-1) && j==(n-1)) {return sum;}
if()


*/    
    
    
//(2)Dungeon Game 地牢遊戲 題: dynamic programming   
};

//=====================================
    int helper1(vector<vector<int>>& grid){
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        
        dp[0][0]=grid[0][0];
        for(int i=1;i<grid.size();i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1; i<grid[0].size(); i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        
        for(int i=1; i<grid.size(); i++){
            for(int j=1; j<grid[0].size(); j++){
                dp[i][j]=grid[i][j]+min(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp.back().back();
    }
    
    int helper0(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));//dp[m][n];//儲存min sum
        int sum = 0;
        
        for(int i=0; i<m; i++){
            sum = sum + grid[i][0];
            dp[i][0] = sum;
        }

        sum = 0;
        for(int i=0; i<n; i++){
            sum = sum + grid[0][i];
            dp[0][i] = sum;
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];        
    }


