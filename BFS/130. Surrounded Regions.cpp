//===類似題===
959. Regions Cut By Slashes
286. Walls and Gates

//===思路===
(*)BFS: 窮舉同一層所有滿足條件的可能
-要push至queue中的數值要先做運算
--沒有先將連接邊界的'O'位置, 將其先改'#',
 所以會將座標值為'O'的, 重複加入queue中, 導致queue越來越大, 最後導致time limited eceeded
//====
void solve(vector<vector<char>>& board){
    int m = board.size(),n = board[0].size();
    vector<vector<int>> dirs{{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    queue<vector<int>> q;

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if((i==0||i==m-1||j==0||j==n-1) && board[i][j]=='O'){
                q.push({i,j});
                board[i][j]='#';

                while(!q.empty()){
                    vector<int> p = q.front(); q.pop();
                    for(vector<int> dir:dirs){
                        int x=p[0]+dir[0],y=p[1]+dir[1];
                        if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='O') {
                            board[x][y]='#';
                            q.push({x,y});
                        }        
                    }
                }
            }
        }
    }    
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(board[i][j]=='O') board[i][j]='X';
            if(board[i][j]=='#') board[i][j]='O';
        }
    }
}



void solve(vector<vector<char>>& board){  
    int m = board.size(),n=board[0].size();
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    queue<vector<int>> q;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if((i==0||i==m-1||j==0||j==n-1)&&board[i][j]=='O'){
                q.push({i,j});                
                board[i][j]='#';

                while(!q.empty()){
                    vector<int> pos=q.front();q.pop();
                    for(auto dir:dirs){
                        int x=pos[0]+dir[0], y=pos[1]+dir[1];
                        if(x<0||x>=m||y<0||y>=n||board[x][y]!='O') continue;
                        board[x][y]='#'; 
                        q.push({x,y});
                    }
                }
            } 
        }
    }
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(board[i][j]=='O') board[i][j]='X';
            if(board[i][j]=='#') board[i][j]='O';
        }
    }
}
//=======================================
void solve(vector<vector<char>>& board){  
    int m = board.size(),n=board[0].size();
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    queue<vector<int>> q;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if((i==0||i==m-1||j==0||j==n-1)&&board[i][j]=='O'){
                q.push({i,j});                
                board[i][j]='#';
                while(!q.empty()){
                    vector<int> pos=q.front();q.pop();
                    for(auto dir:dirs){
                        int x=pos[0]+dir[0], y=pos[1]+dir[1];
                        if(x>0 && x<(m-1) && y>0 && y<(n-1) && board[x][y]=='O') {
                            board[x][y]='#'; q.push({x,y}); 
                        }
                    }
                }
            } 
        }
    }
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(board[i][j]=='O') board[i][j]='X';
            if(board[i][j]=='#') board[i][j]='O';
        }
    }
}
//==== Time limited Exceeded===
(*)原因: 沒有先將連接邊界的'O'位置, 將其先改'#',
 所以會將座標值為'O'的, 重複加入queue中, 導致queue越來越大, 最後導致time limited eceeded


    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if((i==0||i==m-1||j==0||j==n-1)&&board[i][j]=='O'){
                q.push({i,j});         
                while(!q.empty()){
                    vector<int> pos=q.front();q.pop();
                    board[pos[0]][pos[1]]='#';
                    for(auto dir:dirs){
                        int x=pos[0]+dir[0], y=pos[1]+dir[1];
                        if(x>0 && x<(m-1) && y>0 && y<(n-1) && board[x][y]=='O') { q.push({x,y});}
                        //沒有先將連接邊界的'O'位置, 將其先改'#'
                        //所以會將座標值為'O'的, 重複加入queue中, 導致queue越來越大, 最後導致time limited eceeded
                    }
                }
            } 
        }
    }

