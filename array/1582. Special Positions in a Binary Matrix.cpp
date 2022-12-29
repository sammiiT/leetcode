//====類似題===
1583. Count Unhappy Friends
2482. Difference Between Ones and Zeros in Row and Column

//====思路=====
1.建立row陣列, column陣列;可記錄在matrix中1在row和column出現的次數
2.當出現1的時候分別記錄column, row的次數;累加
3.再重新遍歷一次matrix,出現1的時候跟column和row的數值做比對, 如果都是1, 就算滿足條件一次

//=========
int helper0(vector<vector<int>>& mat){
        int n = mat.size(), m= mat[0].size();
        vector<int> r(n,0);
        vector<int> c(m,0);
        int res = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]){
                    r[i]++; c[j]++;
                }        
            }
        }    

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] && r[i]==1 && c[j]==1) res++;
            }    
        }   
        return res;
}

int numSpecial(vector<vector<int>>& mat) {
    return  helper0(mat);    
}
