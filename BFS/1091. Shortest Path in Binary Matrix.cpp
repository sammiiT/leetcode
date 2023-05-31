//===類似題===
1778. Shortest Path in a Hidden Grid
2435. Paths in Matrix Whose Sum Is Divisible by K

//===思路===
(*)BFS

(*)一個node衍伸出node所有的child, 所有同一層的child, 都在同一層level運算
-當計算每層child時, 都會累加一次
- 如果同一層的child的座標發生了　ｘ== (n-1) && y==(n-1) , 則直接回傳累加次數, 此累加次數即為最少路徑 
//=====
int shortestPathBinaryMatrix(vector<vector<int>>& grid){
    if(grid[0][0]==1) return -1;
    int res = 0, n = grid.size();
    set<vector<int>> visited;
    visited.insert({0,0});
    queue<vector<int>> q{{0,0}};
    
    vector<vector<int>> dirs{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    while(!q.empty()){
        ++res;
        for(int i=q.size();i>0;i--){
            auto t = q.front();q.pop();
            if(t[0]==n-1&&t[1]==n-1) return res;
            for(auto dir:dirs){
                int x=t[0]+dir[0], y=t[1]+dir[1];
                if(x<0||x>=n||y<0||y>=n||grid[x][y]==1||visited.count({x,y})) continue;
                visited.insert({x,y});
                q.push({x,y});
            }
        }
    }
    return -1;
}
//===作法2
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    if(grid[0][0]) return -1;

    vector<vector<int>> dirs{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};    
    queue<vector<int>> q;
    q.push({0,0,1});
    visited[0][0]=1;

    while(!q.empty()){
        vector<int> p=q.front();q.pop();
        if(p[0]==m-1 && p[1]==n-1) return p[2];
        for(auto dir:dirs){
            int x=p[0]-dir[0],y=p[1]+dir[1];
            int count = p[2];
            if(x<0||x>=m||y<0||y>=n||grid[x][y]||visited[x][y]) continue;
            visited[x][y]=1;
            q.push({x,y,count+1});
        }
    }
    return -1;

}
//===思路2===
(*)DFS算法會造成time limited exceeded

void helper(vector<vector<int>>& grid, 
            int x, 
            int y, 
            vector<vector<bool>>& visited, 
            int path, 
            int& minPath){
    if(x==grid.size() && y == grid[0].size()) {
        minPath = min(minPath, path);
        return;
    }
    if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||visited[x][y]||grid[x][y]==1) return;

// grid[x][y]==0;
    path+=1;
    visited[x][y]=true;
    
    helper(grid,x+1,y,visited,path,minPath);
    helper(grid,x-1,y,visited,path,minPath);
    helper(grid,x,y+1,visited,path,minPath);
    helper(grid,x,y-1,visited,path,minPath);
    
    helper(grid,x+1,y+1,visited,path,minPath);
    helper(grid,x-1,y-1,visited,path,minPath);
    helper(grid,x+1,y-1,visited,path,minPath);
    helper(grid,x-1,y+1,visited,path,minPath);
    visited[x][y]=false;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
    int minPath = INT_MAX;
    helper(grid,0,0,visited,0,minPath);
    return (minPath==INT_MAX)?(-1):minPath;        
}
