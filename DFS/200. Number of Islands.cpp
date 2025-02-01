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

//===思路2====
(*)union find
(*)搜尋root,如果root不相同,則合併
-因為由圖做思考, 每次都考慮相鄰位置是否等於'1'
-相鄰位置的root不相同, 所以要設定成相同root, 並將兩個獨立的群組做合併

    
int find(int node, vector<int>& parents){
    if(parents[node]!=node){
        return parents[node]=find(parents[node],parents);
    }
    return node;
/*    while(parents[node]!=node){
        parents[node]=parents[parents[node]];
        node = parents[node];
    }
    return node;*/
}
int numIslands(vector<vector<char>> grid){
    vector<vector<int>> dirs = {{1,0},{0,1}};
    int nums = 0;
    int rows = grid.size();
    int cols =grid[0].size();
    vector<int> parents(rows*cols,-1);
    
    for(int i=0; i<rows; ++i){//初始化, 先建立每一個位置, 對應一個群組
        for(int j=0; j<cols; ++j){
            if(grid[i][j]=='1') {
                parents[i*cols+j]=i*cols+j;//2d線性化
                nums++;
            }
        }
    }
    for(int i=0; i<rows; ++i){
        for(int j=0;j<cols; ++j){
            if(grid[i][j]=='1'){
                int id = i*cols+j;
                for(vector<int> dir:dirs){
                    int x=i+dir[0],y=j+dir[1];
                    if(x>=rows||y>=cols||grid[x][y]=='0') continue;
                    
                    int nid = x*cols+y;
                    int root1 = find(id,parents);//搜尋root
                    int root2 = find(nid,parents);
                    if(root1!=root2){//合併
                        parents[root2]=root1;
                        nums--;
                    }
                }
            }
        }
    }
    return nums;  
}

==== union find 造成time limited exceeded ===
(*)每一個節點會延伸出四個節點做運算
- 造成time limited exceeded

(*)相較於上一個算法, 一個點只延伸出兩個節點做運算


int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    //vector<vector<int>> dirs = {{1,0},{0,1}};
    int m=grid.size(),n=grid[0].size();
    int count=0;
    vector<int> roots(m*n,-1);

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(grid[i][j]=='0') continue;
            int id = i*n+j;
            roots[id]=id;
            count++;
            for(vector<int> dir:dirs){
                int x=i+dir[0],y=j+dir[1]; 
                int nid = x*n+y;
                if(x<0||x>=m||y<0||y>=n||roots[nid]==-1) continue;
                int rc=findRoot(id,roots), rn=findRoot(nid,roots);
                if(rc!=rn){
                    roots[rn]=rc;
                    --count;
                }
            }
        }
    }
    return count;
}






