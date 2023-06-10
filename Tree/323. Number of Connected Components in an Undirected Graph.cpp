//===類似題===


//===思路===
(*)BFS + DFS: DFS概念較多, 因為是用遞迴,一直往下一個level作運算
(*) [[0, 1], [1, 2], [2, 3], [3, 4]]
- 從0開始,所以可以當成矩陣的index; 0-index
- 如果在同一個unidirected_graph, 則節點一定會被拜訪

(*)
不設定y分量個數, 因為有些節點只有一個neighbor,有些節點有兩個neighbor;所以不預設y分量個數
vector<vector<int>> g(n);//每一個節點的neighbor

(*)判斷節點是否拜訪過
vector<bool> visited
//=====
void dfs(vector<vector<int>>& g, vector<bool>& visited, int i){
  if(visited[i]) return;
  visited[i]=true;
  for(int j=0; j<g[i].size(); ++j){
    dfs(g, visited, g[i][j]);//在同一層裡面算是BFS
  }
}
int countComponents(int n, vector<pair<int, int> >& edges) {
  vector<vector<int>> g(n);
  vector<bool> visited(n,false);
  int res=0;
  for(auto p:edges){//建立每一個節點的neighbor
    g[p.first].push_back(p.second);
    g[p.second].push_back(p.first);
  }
  
  for(int i=0; i<n; ++i){
    if(visited[i]) continue;
    dfs(g,visited,i);
    res++;
  }
  return res;
}
//===思路2===
(*)從0開始, 0-index
- 建立vector<bool> visited, 判斷節點是否被遍歷過; index = 節點
- 建立unordered_map<int,vector<int>> mp, 紀錄每一個節點的相鄰節點; key = 節點, value = 相鄰節點  
- 每次遍歷完所有的graph,就將result累加一次


void dfs(int i,//節點 
         vector<bool>& visited,//判斷節點是否遍歷過 
         unordered_map<int,vector<int>>& mp){//每一個節點的相鄰節點
    if(visited[i]) return;
    visited[i]=true;
    for(int p: mp[i]){
        dfs(p,visited,mp);
    }
}

int countComponents(int n, vector<pair<int, int> >& edges) {
    int res = 0;
    
    vector<bool> visited(n,false); 
    unordered_map<int,vector<int>> mp;
    
    for(auto p:edges){
        mp[p.first].push_back(p.second);
        mp[p.second].push_back(p.first);
    }
    
    for(int i=0; i<n; ++i){
         if(visited[i]) continue;//節點是否有遍歷過,是否存在於一個connection中
         dfs(i,visited,mp);
         res++;
    }
    return res;
}
