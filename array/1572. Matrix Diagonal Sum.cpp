//===類似題===
1573. Number of Ways to Split a String
2133. Check if Every Row and Column Contains All Numbers
2319. Check if Matrix Is X-Matrix

//===思路===
1.遍歷所有位址
2.(i,i)位址全部加起來
3.(i,n-1-i)位址全部加起來

//====
int helper0(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==j) res+=mat[i][j];
            else if(j==(n-1-i)) res+=mat[i][j];        
        }
    }
    return res;;
}

int diagonalSum(vector<vector<int>>& mat) {
    return helper0(mat);
}
