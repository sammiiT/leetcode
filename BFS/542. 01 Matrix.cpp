//===類似題===
766. Toeplitz Matrix
1730. Shortest Path to Get Food
2123. Minimum Operations to Remove Adjacent Ones in Matrix
2482. Difference Between Ones and Zeros in Row and Column
//===思路===


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
            if(x<0||x>=m||y<0||y>=n||mat[x][y]<=mat[p.first][p.second]+1) continue;
//            matrix[x][y]>matrix[p.first][p.second]+1
                mat[x][y]=mat[p.first][p.second]+1;
                q.push({x,y});
        }
    }
    return mat;
}
