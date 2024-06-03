//===more challenge ===
2087. Minimum Cost Homecoming of a Robot in a Grid
2088. Count Fertile Pyramids in a Land

//===思路1===
int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    unordered_map<int,int> ump;
    int res = 0;

    for(int i=0; i<m; ++i){
        if(matrix[i][0]){
            dp[i][0] = 1;
            ump[1]++;
        }
    }

    for(int i=1; i<n; ++i) {//從1開始, 不然會重複計算[0][0]
        if(matrix[0][i]){
            dp[0][i] = 1;
            ump[1]++;
        }
    }

    for(int i = 1; i<m; ++i){
        for(int j=1; j<n; ++j){
            if(matrix[i][j]){
                if(matrix[i-1][j] && matrix[i][j-1]){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                } else{
                    dp[i][j]=1;
                }
                
                for(int k=1; k<=dp[i][j]; ++k){//每一種邊長會向下相容較小邊長的square
                    ump[k]++;
                }
            }
        }
    }

    for(auto it: ump){
        res+=it.second;
    }
    return res;        
}

//===思路2===
(*)不記錄每邊長的個數
(*)若邊長為3;一定包含一個邊長為2, 一個邊長為1的正方形, 所以直接相加
    
int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    int res = 0;

    for(int i=0; i<m; ++i){
        if(matrix[i][0]){
            dp[i][0] = 1;
            res++;
        }
    }

    for(int i=1; i<n; ++i) {
        if(matrix[0][i]){
            dp[0][i] = 1;
            res++;
        }
    }

    for(int i = 1; i<m; ++i){
        for(int j=1; j<n; ++j){

            if(matrix[i][j]){
                if(matrix[i-1][j] && matrix[i][j-1]){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;

                }
                else{
                    dp[i][j]=1;
                }
                res = res + dp[i][j];
            }
        }
    }
    return res;
}
