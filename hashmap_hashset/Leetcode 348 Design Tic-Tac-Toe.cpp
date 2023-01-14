//===類似題===


//===思路1===
1.每一次填入新的位置時,判斷
直向,
橫向,
左上,右下對角線 (判斷是否在對角線上)=>判斷條件不一樣 if(row==col)
右上,左下對角線 (判斷是否在對角線上)=> if(col+row==n-1)
//====
class TicTacToe {
public:
TicTacToe(int n){
    board.resize(n,vector<int>(n,0));
}

int move(int row, int col, int player){
    board[row][col] =player;//填入
    int i=0, j=0, n=board.size();

    for(j=1; j<n; j++){
        if(board[row][j]!=board[row][j-1]) break;
    }
    if(j==n) return player; //在某條row, 連成一條直線
    
    for(int i=1;i<n;i++){
        if(board[i][col]!=board[i-1][col]) break;
    }
    if(i==n) return player;//在某一條column,連成一條線

//判斷對角線:左上,右下 
    if(row==col){
        for(i=1; i<n; i++){
            if(board[i][i]!=board[i-1][i-1]) break;
        }
        if(i==n) return player;
    }
    
//判斷對角線:右上,左下 (對角線不能用上一種方式判斷)
    if(col+row==n-1){//if(row==col){
        for(int i=1;i<n;i++){
            if(board[i][n-1-i]!=board[i-1][n-1-(i-1)]) break;
        }
        if(i==n) return player;
    }
    return 0;
}
private:
    vector<vector<int>> board;
};

//===思路2===
1.設定兩vector, 一個表示rows,一個代表cols
rows的陣列元素代表每一個"列"的 相同符號數目, 如果數值等於 遊戲的邊長n, 則表示一列連線
cols的陣列元素代表每一個"行"的 相同符號數目, 如果數值等於 遊戲的邊長n, 則表示一行連線

2.設定對角線變數diag,rev_diag
diag(左上右下) : 如果diag也等於邊長,表示對角線連線 
rev_diag(右上左下) : 如果rev_diag也等於邊長,表示對角線連線
//======
class TicTacToe {
public:

TicTacToe(int n):rows(n),cols(n),diag(0),rev_diag(0),N(n){
}

int move(int row, int col, int player){
    int add = (player==1)?1:-1;
    rows[row]+=add;
    cols[col]+=add;
    diag+=(row==col?add:0);
    rev_diag+=((row+col==N-1)?add:0);
    
    return (abs(rows[row])==N|| abs(cols[col])==N|| abs(diag)==N|| abs(rev_diag)==N);
}

private:
vector<int> rows,cols;
int diag, rev_diag, N;

};










