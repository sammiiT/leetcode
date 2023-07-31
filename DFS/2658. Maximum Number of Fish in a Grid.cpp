//===類似題===
2658. Maximum Number of Fish in a Grid
961. N-Repeated Element in Size 2N Array
1329. Sort the Matrix Diagonally
910. Smallest Range II
//===思路===
(*)DFS算法

4 5 6
0 1 0
2 3 4

(*)以上圖為例,5可以往1, 也可以往6,所以,結果要累加
(*)因為"走分岔路徑,結果是要累加", 所以visited在回到上一層不用設定回'0' 
(*)從每一個點(x,y)開始, 計算累加值(包含分岔)  
(*)每一個點的遍歷值, maximum 做比較
(*)最後回傳maximum  
//===
void helper(vector<vector<int>>& grid, 
            int x, 
            int y, 
            vector<vector<bool>>& visited, 
            int& count){
    
    if(x<0||x==grid.size()||y<0||y==grid[0].size()||visited[x][y]||grid[x][y]==0) return;
    
    visited[x][y]=1;
    count+=grid[x][y];
    helper(grid,x-1,y,visited,count);
    helper(grid,x,y+1,visited,count);
    helper(grid,x+1,y,visited,count);
    helper(grid,x,y-1,visited,count);
}

int findMaxFish(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    vector<vector<bool>> visited(m,vector<bool>(n,0));

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            int count = 0;
            if(visited[i][j]) continue;
            helper(grid,i,j,visited,count);
            visited[i][j]=1; 
            res = max(res,count);       
        }
    }
    return res;
}
