//===類似題===
303. Range Sum Query - Immutable
308. Range Sum Query 2D - Mutable
//===思路===
(*)prefix_sum
1.將matrix中每一個row做"累加陣列"計算
2.for loop計算每一個row中[col1:col2]範圍的累加值

(*)範圍[i:j]總和
[j]-(i==0)?0:[j-1]

//===
class NumMatrix {
public:
NumMatrix(vector<vector<int>>& matrix):mtx(matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; ++i){
        for(int j=1; j<m; ++j){
            mtx[i][j]=mtx[i][j-1]+mtx[i][j];
        }
    }
}
    
int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i=row1; i<=row2; ++i){
            res+= mtx[i][col2]-((col1==0)?0:mtx[i][col1-1]);
        }
        return res;
}
private:
    vector<vector<int>>& mtx;
};
