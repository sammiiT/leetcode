//===類似題====
241. Different Ways to Add Parentheses
723. Candy Crush
1697. Checking Existence of Edge Length Limited Paths
1441. Build an Array With Stack Operations

//====思路====
1.從數列可知任何不在上邊界, 左邊界位置上的數值, 皆大於"左", "上", "左上"的數值; 如下
  1   4   7   11  15
  2   5   8   12  19
  3   6   9   16  22
  10  13  14  17  24
  18  21  23  26  30

2.從"18"位址開始算起, 如果大於, 往右移(++j), 如果小於(--i),往上移; 最後可得解  
  
//=====
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i=matrix.size()-1,j = 0;
    while(i>=0 && j<matrix[0].size()){
        if(matrix[i][j]>target) --i;
        else if(matrix[i][j]<target) ++j;
        else if(matrix[i][j]==target) return true;
    }
    return false;  
}
