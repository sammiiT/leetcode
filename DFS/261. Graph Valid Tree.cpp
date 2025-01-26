//=== more challenge ===

//=== 思路 ===
(*) dfs
(*) graph
(*) 判斷是否有產生 "環"
- 利用pre節點來避免回到前一個source節點
- 利用visited[]來判斷是否有環

bool dfs(vector<vector<int>>& g, vector<int>& visited, int cur, int pre){
    if(v[cur]==true) return false;
    v[cur]=1;

    for(vector<int> n:g[cur]){
        if(n!=pre) {//避免回到source節點
          if(!dfs(g,v,n,cur)) return false;
        }
    }
    return true;
}

bool validTree(int n, vector<pair<int, int>>& edges) {
  vector<int, vector<int>> g(n,vector<int>());
  vector<int> visited(n,0);
  
  for(pair<int,int> p:edges){
      g[p.first].push_back(p.second);
      g[.second].push_back(p.first);
  }
  if(!dfs(g,v,0,-1)) return false;
  for(auto i:v) if(!i) return false;// 代表沒有被visited過, 有可能是兩個graph.  
  return true;
}
