//===more challenge===

//===思路===
(*) DFS + memorized buffer
(*) 
vector<vector<int>> memo(m,vector<int>(n,-1));//紀錄每一個節點的最長距離
vector<vector<bool>> visited(m,vector<bool>(n,0));//紀錄執行的路徑有無重複
1.遍歷陣列所有節點,遍歷過程中並記錄每一個節點可走的最長距離
-如果遇到已經走過的節點;visited;則跳過 
-如果已經求得最長距離的節點;memo; 則回傳其值
-每近一個新的層級, 則將節點紀錄為"已訪問"; 跳出此層級前, 將節點設定為"未訪問"

O    O    O    O    O

O    Q<---O<---C    O
     ^         ^
O    O    O    O    O  
     ^         ^
O    O    O    O    O
     ^         ^
O--->A--->O--->B    O
-以memo作為防止重複判斷的條件如上圖所示;兩路徑皆會到達Q節點;
A到Q已經先求得, 所以當B->C->Q時,可取得D的max值坐回傳,不必再重複計算D接下來的路徑


int helper(vector<vector<int>>& matrix, 
            int x, 
            int y, 
            vector<vector<int>>& memo, 
            vector<vector<bool>>& visited, 
            int& mx){
    if(memo[x][y]!=-1 ) return memo[x][y];

    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    int res = 0;
    
    visited[x][y]==1;
    for(auto dir:dirs){
        int i = x+dir[0], j = y+dir[1];
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size()||visited[i][j]||matrix[i][j]<=matrix[x][y]) continue;
        res = max(res, helper(matrix,i,j,memo,visited,mx));
    }
    visited[x][y]=0;
    res+=1;
    memo[x][y]=res;
    mx = max(mx,res);
    return res;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(),n=matrix[0].size();
    vector<vector<int>> memo(m,vector<int>(n,-1));
    vector<vector<bool>> visited(m,vector<bool>(n,0));
    int mx = 0;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            helper(matrix,i,j,memo,visited,mx);
        }    
    }
    return mx;   
}

//==== 寫法2====
vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
int dfs(vector<vector<int>>& matrix, int x, int y, int prev, vector<vector<int>>& visited, vector<vector<int>>& map){
    if(x<0||x>=matrix.size()||y<0||y>=matrix[0].size()||visited[x][y]||matrix[x][y]<=prev) return 0;
    if(map[x][y]>0) return map[x][y];
    
     int res  = 0;
    visited[x][y]=1;
    for(vector<int> dir:dirs){
        int val = 0;
        val = dfs(matrix, x+dir[0], y+dir[1], matrix[x][y], visited, map);
        res = max(res,val);//res is the maximum value;
    }
    map[x][y] =  max(map[x][y],res+1);
    visited[x][y]=0;
    return map[x][y];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    vector<vector<int>> map(m, vector<int>(n,-1));
    int res = 0;
    
    for(int i=0; i<matrix.size(); ++i){
        for(int j=0; j<matrix[0].size(); ++j){
            if(map[i][j]!=(-1)) continue;
            int mx = 0;
            mx = dfs(matrix,i,j, INT_MIN, visited,map); 
            res = max(res,mx);
        }
    }    
    return res;
}




