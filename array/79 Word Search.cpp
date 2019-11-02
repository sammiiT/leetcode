class Solution {
public:
// bool exist(vector<vector<char>>& board, string word) {
//         if (board.empty() || board[0].empty()) return false;
//         int row = board.size(), col = board[0].size();
//         vector<vector<bool>> visited(row, vector<bool>(col, false));
//         for (int i = 0; i < row; ++i) {
//             for (int j = 0; j < col; ++j) {
//                 if (search(board, word, 0, i, j, visited)) return true;
//             }
//         }
//         return false;
//     }
//     bool search(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
//         if (idx == word.size()) return true;
//         int m = board.size(), n = board[0].size();
//         if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
//         visited[i][j] = true;
//         bool res = search(board, word, idx + 1, i - 1, j, visited) 
//                  || search(board, word, idx + 1, i + 1, j, visited)
//                  || search(board, word, idx + 1, i, j - 1, visited)
//                  || search(board, word, idx + 1, i, j + 1, visited);
//         visited[i][j] = false;
//         return res;
//     }    
    
    bool exist(vector<vector<char>>& board, string word) {
        // int row,col;
        // row = board.size(); col = board[0].size();
        // if(row<=0 || col<=0) return false;
        // vector<vector<bool>> visited(row,vector<bool>(col,false));
        // for(int i = 0; i<row; ++i){//從任意一點開始,用i,j loop
        //     for(int j = 0; j<col; ++j){
        //         if(search(board,word,0,i,j,visited)) return true;   
        //     }        
        // }
        // return false;
        
        if (board.empty() || board[0].empty()) return false;
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (search(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }

//問題問ˇ共有幾種走法 or 有沒有存在路徑? ===>屬於有沒有存在路徑問題
//有些題目用for 迴圈, 此題不用, 試分析差異  //subsets 
    bool search(vector<vector<char>> &board,
                string word,
                int idx,
                int i,
                int j,
                vector<vector<bool>> &visited){
        
        if(idx==word.size()) return true;
        int row = board.size(),col=board[0].size();
        if(i<0||j<0||i>row-1||j>col-1   //(i,j)不在board範圍之內
           ||visited[i][j]          //重複讀取
           ||board[i][j]!=word[idx])//獨取到的數值不滿足word的條件 
            return false;
     
        bool res;
        visited[i][j] = true;
        res = search(board,word,idx+1,i-1,j,visited)//當下的點往左
            ||search(board,word,idx+1,i+1,j,visited)//當下的點往右
            ||search(board,word,idx+1,i,j-1,visited)//當下的點往下
            ||search(board,word,idx+1,i,j+1,visited);//當下的點往上
        visited[i][j]=false;
        return res;
    }
};



        // std::unordered_map<char,int> m;
        // for(int i=0;i<board.size();++i){
        //     for(int j=0;j<board[0].size();++j){m[board[i][j]]++;}
        // }
        // for(int i=0;i<word.size();++i){
        //     if(m[word[i]] && (--m[word[i]]>=0)){}
        //     else{return false;}    
        // }
        // return true;

