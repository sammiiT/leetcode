
//===思路===
(*)用BFS運算

int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    int m = grid.size(),n=grid[0].size();
    vector<vector<bool>> 
    vector<int> cordX{-1,0,1,0},cordY{0,1,0,-1};
    
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(grid[i][j]=='0'||visited[i][j]) continue;
           res++;

            queue<int> q{{i*n+j}};
            while(!q.empty()){
                int tmp = q.front(); q.pop();
                for(int p=0; p<4; ++p){
                    int x = tmp/n +cordX[p], y = tmp%n+cordY[p];
                    if(x<0||x>=m||y<0||y>=n||grid[x][y]=='0'||visited[x][y]) continue;
                    visited[x][y]=true;
                    q.push(x*n+y);
                }
            }
        }
    }
    return res;
}
