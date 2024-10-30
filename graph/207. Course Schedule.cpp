//=== more challenge ===
261. Graph Valid Tree
310. Minimum Height Trees
630. Course Schedule III

//=== 思路 ===
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses,vector<int>());
    vector<int> in(numCourses,0);
    queue<int> q;


    for(int i=0; i<prerequisites.size(); ++i){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        in[prerequisites[i][0]]++;
    }        
    
    for(int i=0;i<in.size();++i){
        if(in[i]==0) q.push(i);//入度為0的節點
    }

    while(!q.empty()){
        int p = q.front();q.pop();
        for(int t:graph[p]){//入度為0節點的"出度"
            in[t]--;
            if(in[t]==0) q.push(t);
        }
    }

    for(int i=0; i<numCourses; ++i){
        if(in[i]!=0) return false;
    }
    return true;
}
