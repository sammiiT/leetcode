//===類似題===

//===思路===
(*)BFS

int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
  int m = maze.size(), n = maze[0].size();
  
  vector<vector<int>> dists(m,vector<int>(n,INT_MAX));//作為visited概念
                    //當遇到[x][y]數值大於過去累加的距離,則代表沒有visited過 
                    //一開始是INT_MAX, 所以第一次遇到,一定都是沒有visited
                    //dists[x][y]最後一定是最小值
  
  vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
  queue<vector<int>> q;
  int res;
  
  q.push(start);
  dists[start[0]][start[1]] = 0;

  while(!q.empty()){
    vector<int> p = q.front();q.pop();
    for(vector<int> dir:dirs){
        int x = p[0],y=p[1];
        int i = dir[0],j=dir[1];
        int dist = 0;
        
        while(x>=0 && x<m && y>=0 && y<n && maze[x][y]){
          x+=i;
          y+=j;
          ++dist;
        }
        x-=i;
        y-=j;
        --dist;
        dist+=dists[p[0]][p[1]];//累加的總距離
        if(dists[x][y]>dist){
          dists[x][y]=dist;
          if(x!=destination[0]||y!=destination[y]) q.push({x,y});
        }
    }
    res = dists[destination[0]][destination[1]];
    return (res==INT_MAX)?-1:res;
    
  }
  
}
