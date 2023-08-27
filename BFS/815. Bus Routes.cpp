//===類似題===
1575. Count All Possible Routes
2361. Minimum Costs Using the Train Line
//===思路===


//=======

int numBusesToDestination_bfs(vector<vector<int>>& routes, int S, int T) {
    unordered_map<int,vector<int>> mp;//stop, route
    unordered_map<int,int> visited;//route, visited or not
    queue<int> q;//stop
    int res =0;

    if(S==T) return 0;
    for(int i=0; i<routes.size(); ++i){
        for(int j=0;j<routes[i].size(); ++j){
            mp[routes[i][j]].push_back(i); //stop to route  
        }
    }
  
    q.push(S);
//  visited[route]=1;//不能有此描述, 因為有可能在S的route, 就能到達destination.  
    while(!q.empty()){
        res++;
        for(int i=q.size(); i>0; ++i){
            int t = q.front();q.pop();//t==stop
            //if(visited[t]) continue;//計算自己的route是否能到達destination, 所以 不用在一開始就將visited紀錄進去
            for(int route:mp[t]){
                if(visited[route]) continue;
                visited[route]=1;
                for(int stop:routes[route]){
                  if(stop==T) return res;
                    q.push(stop);
                }
            }        
        }
    }
    return -1;

  
}
