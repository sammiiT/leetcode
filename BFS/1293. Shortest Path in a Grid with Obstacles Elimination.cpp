//===類似題===
1778. Shortest Path in a Hidden Grid
1730. Shortest Path to Get Food
2290. Minimum Obstacle Removal to Reach Corner

//===思路===

(*)
while(!q.empty()){
  for(int i=q.size(); i>0; --i){
    vector<int> p=q.front();q.pop();
    for(vector<int> dir:dirs){
      int x=p[0]+dir[0],y=p[1]+dir[1];
      if(x==m-1 && y==n-1) return res; //放在這邊會錯誤, 因為沒有考慮到初始原點
      ...                              /* grid只有一個element的matrix; gird={{0}};
                                        在這裡運算,會沒考慮到第一次q.push({0,0,k})的情況
                                        */
    }
  }
  res++;//運算完,才做次數+1的動作, 因為不考慮原點; 只考慮移動的次數
}
修正:
while(!q.empty()){
  for(int i=q.size(); i>0; --i){
    vector<int> p=q.front();q.pop();
    if(p[0]==m-1 && p[1]==n-1) return res;
    for(vector<int> dir:dirs){
        int x=p[0]+dir[0], y=p[1]+dir[1];
        ...
    }
  }
  res++;//運算完,才做次數+1的動作, 因為不考慮原點; 只考慮移動的次數
}

(*)
if(cntk<0 || cntk<=visited[x][y]) continue;
其中cntk<=visited[x][y]可以參考 542. 01 Matrix.cpp 

//====
int shortestPath(vector<vector<int>>& grid, int k) {
    int m=grid.size(),n=grid[0].size();
    int res=0;
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> visited(m,vector<int>(n,-1));
    queue<vector<int>> q;
  
    q.push({0,0,k});
    visited[0][0]=k;//remain k times

    while(!q.empty()){
        for(int i=q.size(); i>0; --i){
            vector<int> p = q.front();q.pop();
            //p[0],p[1],p[2]
            if(p[0]==m-1 && p[1]==n-1) return res;  
            for(vector<int> dir:dirs){
                int x = p[0]+dir[0], y = p[1]+dir[1];
                //if(x==m-1 && y==n-1) return res;//
                
                if(x<0||x==m||y<0||y==n) continue;
                int cntk = p[2]-grid[x][y];
                if(cntk<0 || cntk<=visited[x][y]) continue;//此概念可以參考 542. 01 Matrix.cpp 
                push({x,y,cntk});
                visiedt[x][y]=cntk;
            }
        }
        res++;
    }
    return -1;
}

