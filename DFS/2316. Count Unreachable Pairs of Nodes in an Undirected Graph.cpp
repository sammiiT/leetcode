//===類似題===
2573. Find the String with LCP
310. Minimum Height Trees
1462. Course Schedule IV
//===思路===
(*)用DFS 紀錄每一個unidirect-graph的個數
(*)所有不連通的pair個數 node[i]*(n-node[i]);  最後總和還要再/2

void dfs(vector<vector<int>>& g, vector<bool>& visited, int i, int& count){
    if(visited[i]) return;
    visited[i]=true;
    count++;
    for(int j=0; j<g[i].size(); ++j){
        dfs(g,visited,g[i][j],count);
    }
}

long long countPairs(int n, vector<vector<int>>& edges) {
    long long ret = 0;
    vector<long> res;
    vector<vector<int>> g(n);
    vector<bool> visited(n,false);

    for(vector<int>& edge: edges){
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }
    for(int i=0;i<n;++i){
        int count = 0;
        if(visited[i]) continue;
        dfs(g, visited, i, count);
        res.push_back(count);
    }
    for(int i=0; i<res.size(); ++i){
        ret +=(res[i]*(n-res[i]));
    }
    return ret/2;
}
