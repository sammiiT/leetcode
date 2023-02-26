//===類似題===
74. Search a 2D Matrix
289. Game of Life
2125. Number of Laser Beams in a Bank
2123. Minimum Operations to Remove Adjacent Ones in Matrix

//===思路===
(*)in-place:  transforms input using no auxiliary data structure. 只能在input上做運算,不能另創新解
1.建立row, col陣列, 紀錄出現0的位址
2.兩次for迴圈, 第一次紀錄出現0的位址
3.第二次for迴圈, 依據紀錄的0位址,來更改matrix的element

//======
void helper0(vector<vector<int>>& matrix) {
    vector<int> row(matrix.size(),0);
    vector<int> col(matrix[0].size(),0);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(row[i]||col[j]) matrix[i][j]=0;
        }
    }
}

    void setZeroes(vector<vector<int>>& matrix) {
     helper0(matrix);   
    }
};
