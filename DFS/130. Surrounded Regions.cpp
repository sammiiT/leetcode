//===類似題===
959. Regions Cut By Slashes
286. Walls and Gates

//===思路===
(*)DFS 求解
1. 先對周圍是'O'的位置設定為'#'; 利用DFS
2. 如果連接 周圍是'O'的位址也是'O',將其連結的位址設為'#'; (利用DFS計算)
3. 因為只從周圍是'O'計算得到'#', 所以沒有相連接的區域是'O', 不會受影響
4. 遍歷整個陣列,先判斷是否為'O', 並將其設定為'X'
4.1 再判斷,如果是'#' ,將其設定為'O'
4.2 判斷順序不能相反,會錯誤

//=====
void dfs2(vector<vector<char>>& board, int i, int j){
    if(i<0||i==board.size()||j<0||j==board[0].size()||board[i][j]=='#'||board[i][j]=='X') return;
    dfs2(board,i-1,j);
    dfs2(board,i,j+1);
    dfs2(board,i+1,j);
    dfs2(board,i,j-1);
}
  
void dfs1(vector<vector<char>>& board, int i,int j){
    if(board[i][j]=='O'){
        board[i][j]='#';
        if(i>0 && board[i-1][j]=='O')                 helper(board,i-1,j);
        if(j<board[i].size()-1 && board[i][j+1]=='O') helper(board,i,j+1);
        if(i<board.size()-1 && board[i+1][j]=='O')    helper(board,i+1,j);
        if(j>0 && board[i][j-1]=='O')                 helper(board,i,j-1);

    }
}

    void solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[i].size(); ++j){
                if((i==0||i==board.size()-1||j==0||j==board[i].size()-1) && board[i][j]=='O')
                    dfs1(board,i,j);
            }
        }
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[i].size();++j){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';                
            }
        }
    }
