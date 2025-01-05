//=== more challenge ===
1916. Count Ways to Build Rooms in an Ant Colony
672. Bulb Switcher II
1319. Number of Operations to Make Network Connected

//=== 思路 ===
(*)DFS
(*)建立graph

int dfs(int header, 
        vector<int>& informTime,
        unordered_map<int,vector<int>>& ump){

    int maximum = 0;        
    for(int i=0; i<ump[header].size(); ++i){
        maximum = max(maximum, dfs(ump[header][i],informTime,ump)+informTime[header]);
    }    
    return maximum;
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    unordered_map<int,vector<int>> subordinates;
    for(int i=0; i<manager.size(); ++i)
        if(manager[i]!=-1) subordinates[manager[i]].push_back(i);

    return dfs(headID,informTime,subordinates);
}
