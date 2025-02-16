#===more challenge===


#===思路===
(*)BFS
(*)可參考01 matrix
  void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size(), n = rooms[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};

    for(int i=0;i<m; ++i){
        for(int j=0;j<n; ++j){
            if(rooms[i][j]==0) q.push({i,j});
        }
    }
    
    while(!q.empty()){
        pair<int,int> p=q.front();q.pop();
        for(vector<int> dir:dirs){
            int x = p.first+dir[0];
            int y = p.second+dir[1];
            if(x<0||x>=m||y<0||y>=n||rooms[x][y]==-1||rooms[x][y]<=rooms[p.first][p.second])
                continue;
            //rooms[x][y]>rooms[p.first][p.second]
            rooms[x][y]=rooms[p.first][p.second]+1;
            q.push({x,y});
        }
    }
}
