//=== more challenge ===
323. Number of Connected Components in an Undirected Graph
657. Robot Return to Origin
734. Sentence Similarity
//===思路===
(*)先建立graph
(*)利用DFS求解

void dfs(int start, map<int,vector<int>>& connect, vector<int>& visited){
    if(visited[start]) return;
    visited[start]=1;
    for(int i=0;i<connect[start].size();++i){
        dfs(connect[start][i],connect,visited);
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int res=0;    
    map<int,vector<int>> connect;
    vector<int> visited(isConnected.size(),0);
//建立graph    
    for(int i=0; i<isConnected.size(); ++i){
        for(int j=0;j<isConnected[i].size();++j){
            if(isConnected[i][j]==1)
                connect[i].push_back(j);
        }
    }
// dfs 求解  
    for(auto it: connect){
        if(visited[it.first]==1) continue;
        dfs(it.first,connect,visited);
        res+=1;
    }
    return res;
}
