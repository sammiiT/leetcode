#=== 思路 ===
(*)dfs


bool isValid(int row, int col, vector<int>& queen){
    for(int i=0;i<row;++i){
        if(col==queen[i]|| abs(row-i)==abs(col-queen[i])) return false;
    }
    return true;
}


void dfs(int n,int row, vector<int>& queen, int& res){
    if(row==n){
        res+=1;
        return;
    }
    
    for(int i=0; i<n; ++i){
        if(!isValid(row,i,queen)) {
            continue;
        }
        queen[row]=i;
        dfs(n,row+1,queen,res);
        queen[row]=-1;
    }
}


int totalNQueens(int n) {
    vector<int> queen(n,-1);
    int res=0;
    dfs(n,0,queen,res);
    return res;
}
