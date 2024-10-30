//=== more challenge ===
269. Alien Dictionary
310. Minimum Height Trees
444. Sequence Reconstruction

//=== 思路 ===
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses,vector<int>());
    vector<int> in(numCourses);
    queue<int> q;
    vector<int> res;

    for(int i=0; i<prerequisites.size(); ++i){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        in[prerequisites[i][0]]++;
    }
    for(int i=0; i<numCourses; ++i){
        if(in[i]==0) {
            q.push(i);
            res.push_back(i);
        }
    }

    while(!q.empty()){
        int i = q.front(); q.pop();
        for(int j : graph[i]){
            in[j]--;
            if(in[j]==0){
                q.push(j);
                res.push_back(j);
            }
        }
    }

    return res.size()==numCourses?res:vector<int>();
}
