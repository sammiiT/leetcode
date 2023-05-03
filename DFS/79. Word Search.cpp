//===類似題===
80. Remove Duplicates from Sorted Array II
212. Word Search II
//===思路===
(*)DFS算法; DFS有pre-order的精神, 先運算,再往下一個節點做運算

1.每一個節點都可以當作root節點
2.下一階層的所有可能,都可視為root的child
res =  helper0(board,word,{p.first-1,p.second},visited,out)
         ||helper0(board,word,{p.first+1,p.second},visited,out)
         ||helper0(board,word,{p.first,p.second-1},visited,out)
         ||helper0(board,word,{p.first,p.second+1},visited,out);
所以{p.first-1,p.second};{p.first+1,p.second};{p.first,p.second-1};{p.first,p.second+1}四個點,都是root的child

//=====
bool helper0(vector<vector<char>>& board, 
            string word,
            pair<int,int> p,
            vector<vector<bool>>& visited,
            string out){
    if(p.first==board.size()||p.first==-1||p.second==board[0].size()||p.second==-1||visited[p.first][p.second]) 
        return false;
        
    out +=board[p.first][p.second];
    if(out!=word.substr(0,out.size())) return false;
    if(out==word) return true; 

    int res =0;
    visited[p.first][p.second]=true;
    res =  helper0(board,word,{p.first-1,p.second},visited,out)
         ||helper0(board,word,{p.first+1,p.second},visited,out)
         ||helper0(board,word,{p.first,p.second-1},visited,out)
         ||helper0(board,word,{p.first,p.second+1},visited,out);
    visited[p.first][p.second] = false;
    return res;
}

bool helper1(vector<vector<char>>& board, 
            string word,
            int idx,
            pair<int,int> p,
            vector<vector<bool>>& visited){
    if(idx==word.size()) return true;
    if(p.first==board.size()||p.first==-1||p.second==board[0].size()||p.second==-1||visited[p.first][p.second]) return false;
    if(board[p.first][p.second]!=word[idx]) return false;
    idx++;
    
    int res;
    visited[p.first][p.second]=true;
    res = helper1(board,word,idx,{p.first+1,p.second},visited)
        ||helper1(board,word,idx,{p.first-1,p.second},visited)
        ||helper1(board,word,idx,{p.first,p.second+1},visited)
        ||helper1(board,word,idx,{p.first,p.second-1},visited);
    visited[p.first][p.second]=false;
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
   int m = board.size(),n=board[0].size();
   vector<vector<bool>> visited(m,vector<bool>(n,0));
       
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
           if(helper1(board,word,0,{i,j},visited)) return true;
//               if(helper0(board,word,{i,j},visited,"")) return true;
       }
   }
   return false; 
}

//===思路2==
(*)優化,判斷每一個[x][y]的character是不是滿足 word[idx]的順序
(*)每進入下一個level就判斷idx是否等於word.size()
- 如果idx等於word.dize(),代表上一層的[x][y]排列滿足word

(*)每往下一層, 都會有"上","下","左","右"的路徑可以走
(*)vector<vector<bool>> visited來代表 已經走過的路徑


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {        
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

//====
bool search(vector<vector<char>> &board,
                string word,
                int idx,
                int i,
                int j,
                vector<vector<bool>> &visited){
        
//        if(idx==word.size()) return true;
    if(i<0||j<0||i>row-1||j>col-1   //(i,j)不在board範圍之內
       ||visited[i][j]          //重複讀取
       ||board[i][j]!=word[idx])//獨取到的數值不滿足word的條件 
        return false;
    
    if(idx==word.size()-1) return true;//放在這邊要word.size()-1
         
    bool res;
    visited[i][j] = true;
    res = search(board,word,idx+1,i-1,j,visited)//當下的點往左
        ||search(board,word,idx+1,i+1,j,visited)//當下的點往右
        ||search(board,word,idx+1,i,j-1,visited)//當下的點往下
        ||search(board,word,idx+1,i,j+1,visited);//當下的點往上
    visited[i][j]=false;
    return res;
}


