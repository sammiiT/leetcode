//===類似題===
305. Number of Islands II
286. Walls and Gates
305. Number of Islands II
323. Number of Connected Components in an Undirected Graph

//===思路===
(*)用BFS運算;也可以用DFS做計算, 這邊用BFS

 int bfs(vector<vector<char>>& grid) {
    int res = 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    queue<pair<int,int>> q;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(grid[i][j]=='0' || visited[i][j]==1) continue;
            
            visited[i][j]=1;
            q.push({i,j});//BFS準備
            while(!q.empty()){//BFS開始計算
                pair<int,int> p = q.front();q.pop();
                for(vector<int> dir:dirs){
                    int x = p.first+dir[0],y=p.second+dir[1];
                    if(x<0 ||x==m ||y<0 ||y==n
                    ||visited[x][y]||grid[x][y]=='0') continue;
                    visited[x][y]=1;//滿足條件的, 才放入BFS queue中
                    q.push({x,y});                    
                }
            }
            res+=1;
        }
    }
    return res;
}
   



//===寫法2===
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
//=====

void dfs(vector<vector<char>>& grid, 
            int x, 
            int y, 
            vector<vector<bool>>& visited){
    
if(x<0||x==grid.size()||y<0||y==grid[0].size()||visited[x][y]||grid[x][y]=='0') return;
    
    visited[x][y]=1;
    dfs(grid,x-1,y,visited);
    dfs(grid,x,y+1,visited);
    dfs(grid,x+1,y,visited);
    dfs(grid,x,y-1,visited);
}

void bfs(vector<vector<char>>& grid, int i, int j,vector<vector<bool>>& visited){
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    queue<vector<int>> q;
    q.push({i,j});
    visited[i][j]=1;
    
    while(!q.empty()){
        vector<int> p=q.front();q.pop();
        for(vector<int> dir:dirs){
            int x=dir[0]+p[0],y=dir[1]+p[1];
            if(x<0||x==grid.size()||y<0||y==grid[0].size()||visited[x][y]||grid[x][y]=='0') continue;
            q.push({x,y});
            visited[x][y]=1;
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    int res = 0;
    
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(visited[i][j] || grid[i][j]=='0') continue;
            //dfs(grid,i,j,visited);
            bfs(grid,i,j,visited);
            res++;
        }
    }
    return res;
}
