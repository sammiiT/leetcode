//===類似題===
766. Toeplitz Matrix
1730. Shortest Path to Get Food
2123. Minimum Operations to Remove Adjacent Ones in Matrix
2482. Difference Between Ones and Zeros in Row and Column
//===思路===
(*)BFS算法
1.記錄數值為"0"的位置到queue中, 將數值為"1"的位置更改為INT_MAX
2.下一個"鄰近點"的數值若大於現在的點, 則"鄰近點"的數值就是"現在點"數值 +1

(*) 以下概念可以套用到 1293. Shortest Path in a Grid with Obstacles Elimination ??
0 , 0 , 1 , 1 , 0
遍歷到 (0,1)時, (0,3)最後會變成  2
但算到 (0,4)時, (0,3)最後會反填回 1
    
    
//=======
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m=mat.size(),n=mat[0].size();
    vector<vector<int>> dirs{{-1,0},{0,1},{1,0},{0,-1}};
    queue<pair<int,int>> q;

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(mat[i][j]==0) q.push({i,j});
            else mat[i][j]=INT_MAX;
        }
    }

    while(!q.empty()){
        pair<int,int> p = q.front(); q.pop();
        for(auto dir:dirs){
            int x=p.first+dir[0], y=p.second+dir[1];
//            if(x<0||x>=m||y<0||y>=n||mat[p.first][p.second]+1>=mat[x][y]) continue;
            if(x<0||x>=m||y<0||y>=n||mat[x][y]<=mat[p.first][p.second]+1) continue;
//                mat[x][y]=min(mat[x][y],mat[p.first][p.second]+1);//此描述也可以
                mat[x][y]=mat[p.first][p.second]+1;
                q.push({x,y});
        }
    }
    return mat;
}
