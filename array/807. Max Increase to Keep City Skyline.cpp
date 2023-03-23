//===類似題===
808. Soup Servings
942. DI String Match
2207. Maximize Number of Subsequences in a String
472. Concatenated Words
//===思路===

//===
int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> row(m,0),col(n,0);
    int res = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            row[i] = max(row[i],grid[i][j]);
            col[j] = max(col[j],grid[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            res+= min(row[i]-grid[i][j],col[j]-grid[i][j]);
        }
    }
    return res;
}
