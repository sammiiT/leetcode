//===類似題===
305. Number of Islands II
130. Surrounded Regions
286. Walls and Gates
305. Number of Islands II

//===思路===
(*)DFS
1.遍歷二維陣列中的每一個點[x][y]
2.宣告一個二維陣列,紀錄[x][y]=='1'
- 利用DFS紀錄位址[x][y]=='1'的點 
-在遍歷過程中,因為前一次遍歷而有在visited[x][y]做紀錄的, 則跳到下一個遍歷點 
-在"遍歷"或"DFS"過程中,如果發生[x][y]=='0'或已經被visited[x][y]紀錄, 則返回不做計算
-如果是[x][y]=='1',且visited[x][y]沒有被記錄,則繼續往下一個DFS做運算

3.每一個節點的DFS執行完, 就可以將結果+1


(*)DFS目的是將連接的"1"全部記錄起來;利用visited[x][y]紀錄
(*)visited[x][y]是用來判斷是否被記錄過,是否需繼續往下計算
//======

void helper(vector<vector<char>>& grid,int x, int y, vector<vector<int>>& visited){
    if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]=='0'||visited[x][y]) return;
    visited[x][y]=1;
    helper(grid,x+1,y,visited);
    helper(grid,x-1,y,visited);
    helper(grid,x,y+1,visited);
    helper(grid,x,y-1,visited);
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(),m=grid[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    int res = 0;

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(grid[i][j]=='0'||visited[i][j]) continue;//在"遍歷"或"DFS"過程中,如果發生[x][y]=='0'或已經被visited[x][y]紀錄, 則返回不做計算
            helper(grid,i,j,visited);
            res++;
        }
    }
    return res;    
}
