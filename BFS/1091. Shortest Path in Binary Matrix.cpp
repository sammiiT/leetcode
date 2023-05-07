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
