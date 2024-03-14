//===類似題===


//===思路=====
(*)BFS 羅列同一層滿足題意的所有可能, 並放入queue中

//======
bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
  int m = maze.size(), n = maze[0].size();
  vector<vector<int>> dirs{{-1,0},{0,1},{1,0},{0,-1}};
  vector<vector<bool>>  visited(m,vector<bool>(n,false));
  queue<vector<int>> q;
  q.push({start[0],start[1]});//將所有滿足題意的可能都放入q中
  visited[start[0]][start[1]]=true;
  
  while(!q.empty()){//q中的的element都是滿足題意的位置
    vector<int> p = q.front(); q.pop();
    if(p[0]==destination[0] && p[1]==destination[1]) return true;
    for(auto dir:dirs){
      int x=p[0], y=p[1];
      while(x>=0 && x<m && y>=0 && y<n && maze[x][y]==0){
        x+=dir[0];y+=dir[1];
      }
      x-=dir[0];y-=dir[1];//超出範圍要跳回來
      if(!visited[x][y]){//visited 是用來防止重複走到同一個點
        visited[x][y]=true;
        q.push({x,y});//滿足題意的的位置
      }
    }
  }
  return false;
}

//===寫法2====
(*)也是用BFS

bool hasPath(vector<vector<int>>& maze, 
        vector<int>& start, 
        vector<int>& destination){
    
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    vector<int> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    queue<vector<int>> q;

    if(start==destination) return true;

    q.push(start);
    visited[start[0]][start[1]] = 1;
    
    while(!q.empty()){
        vector<int> p = q.front(); q.pop();
        
        for(vector<int>& dir:dirs){//4 directions
            int i = dir[0], j = dir[1];    
            int x = p[0], y = p[1];
            
            //while(x>=0 && x<m && y>=0 && y<n && maze[x][y]==0 && visited[x][y]==0){//visited在這邊做判斷, 下面會很難計算 
            while(x>=0 && x<m && y>=0 && y<n && maze[x][y]==0){
                x+=i;
                y+=j;
            } 
            //1.超過邊界, 2.遇到邊界
            x-=i;y-=j;//遇到邊界,退回前一格
            if(x==destination[0]&&y==destination[1]) return true;//如果是destination,回傳true
            if(visited[x][y]==1) continue;
            
            q.push({x,y});
            visited[x][y]=1;
        }
    }
    return false;           
}

