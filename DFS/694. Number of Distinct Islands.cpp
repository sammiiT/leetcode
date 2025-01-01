//=== more challenge ===

//===思路====
(*)dfs
(*)
distinct island 是不含rotation相同的, 皆以獨立island計算
因為rotation不屬於相同island, 所以計算原點到island每一個位置的相對距離
每一個點的相對距離的集合都記錄到set<vector<pair<int,int>>>中, 
因為set不可能重複, 所以最後回傳 set.size()即可.

//====
void dfs(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<pair<int,int>>& v){
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}}; 
  
  if(i<0||i>=m||j<0||j>=n||grid[i][j]<=0) return;
  grid[i][j] = -1;
  v.push_back({i-x0,j-y0});
  for(vector<int> dir:dirs){
      dfs(grid,x0,y0,i+dir[0],j+dir[1],v);
  }
}

int numDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    set<vector<pair<int,int>>> res;
    
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(grid[i][j]<=0) continue;
            dfs(grid, i,j,i,j,v);
            res.insert(v);
        }
    }
    return res.size();
}
