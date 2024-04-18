//===類似題===
755. Pour Water
2411. Smallest Subarrays With Maximum Bitwise OR
547. Number of Provinces
2018. Check if Word Can Be Placed In Crossword

//===思路===
(*)DFS 算法
-從四個"邊界"討論,再從每個邊界往內遍歷做判斷, 邊界中的每一個點,水都可以流通, 但可以pacific且atlantic通,需同時成立
--跟surround_region題型很像
-當前一個數值大於新的數值; 代表水"不可以"流通, 回傳
-當前一個數值小於等於新的數值; 則代表水"可以"流通, 繼續往下一個點繼續運算下去

(*)
heights[x][y]: 新的位置高度   
pre: 前一個位置高度
新的位置高度一定要"大於"前一個位置高度, 水才可以流下去

//======
void dfs(vector<vector<int>>& height,int x, int y, int pre, vector<vector<bool>>& visited){
    if(x<0||x>=height.size()||y<0||y>=height[0].size()||visited[x][y]||height[x][y]<pre) return;
    visited[x][y]=true;
    dfs(height,x-1,y,height[x][y],visited);
    dfs(height,x+1,y,height[x][y],visited);
    dfs(height,x,y+1,height[x][y],visited);
    dfs(height,x,y-1,height[x][y],visited);
}
vector<vector<int>> pacificAtlantic_dfs(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m,vector<bool>(n,false));        
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
    
        for(int i=0;i<m;++i){
            dfs(heights,i,0,INT_MIN,pacific);
            dfs(heights,i,n-1,INT_MIN,atlantic);
        }
        for(int i=0;i<n;++i){
            dfs(heights,0,i,INT_MIN,pacific);
            dfs(heights,m-1,i,INT_MIN,atlantic);        
        }

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(pacific[i][j]&&atlantic[i][j]) res.push_back({i,j});        
            }
        }
        return res;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
//    return pacificAtlantic_dfs(heights);
    return pacificAtlantic_bfs(heights);
}
//===思路2===
(*)BFS算法

heights[x][y]:新位置的高度
heights[p[0]][p[1]]:舊位置的高度
新位置的高度 "大於" 舊位置的高度 ; 水才會流動

//======
void bfs(vector<vector<int>>& heights,
        vector<vector<bool>>& visited,
        queue<vector<int>>& q){
    vector<vector<int>> dirs{{-1,0},{0,1},{1,0},{0,-1}};
    
    while(!q.empty()){
        vector<int> p=q.front();q.pop();
        for(vector<int> dir:dirs){
            int x=p[0]+dir[0],y=p[1]+dir[1];
            if(x<0||x>=heights.size()||y<0||y>=heights[0].size()||visited[x][y]
            ||heights[x][y]<heights[p[0]][p[1]]) continue;
            visited[x][y]=true;
            q.push({x,y});
        }        
    }
}

vector<vector<int>> pacificAtlantic_bfs(vector<vector<int>>& heights) {
    int m=heights.size(), n=heights[0].size();
    vector<vector<bool>> pacific(m,vector<bool>(n,false)), atlantic = pacific;
    queue<vector<int>> q1,q2;
    vector<vector<int>> res;

    for(int i=0;i<m;++i){
        q1.push({i,0});//pacific
        q2.push({i,n-1});//atlantic
        pacific[i][0] = true;
        atlantic[i][n-1]=true;
    }
    for(int i=0;i<n;++i){
        q1.push({0,i});//pacific
        q2.push({m-1,i});//atlantic
        pacific[0][i]=true;
        atlantic[m-1][i]=true;
    }
    bfs(heights,pacific,q1);
    bfs(heights,atlantic,q2);
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(pacific[i][j]&&atlantic[i][j]) res.push_back({i,j});           
        }
    }
    return res;
}

