#=== 思路 ===
(*)排列組合型 dfs
(*)pattern:  void dfs(,&out,&res)
out為過程中的解
res為解紀錄


bool isValid(int row, int col, map<int,int>& queen){
    for(auto it:queen){
        if(it.first==row||it.second==col) return false; //rectangle
        if(abs(it.first-row)==abs(it.second-col)) return false;
    }
    return true;
}

void dfs(int n, int start, map<int,int>& queen, vector<vector<pair<int,int>>>& res){
    if(start==n && queen.size()==n) {
        vector<pair<int,int>> out;
        for(auto it:queen){
            out.push_back({it.first,it.second});
        }
        res.push_back(out);
    }
    if(start>=n) return;
    
    for(int i=start;i<n;++i){//n row, n col
        for(int j=0;j<n;++j){
            if(!isValid(i,j,queen)) continue;
            queen[i]=j;
            dfs(n,i+1,queen,res);
            queen.erase(i);
        }
    }
}    

vector<vector<string>> solveNQueens(int n) {
    map<int,int> queen;
    vector<vector<pair<int,int>>> ret;
    vector<vector<string>> res;
    
    dfs(n,0,queen,ret);
  
    for(int i=0;i<ret.size();++i){
        vector<pair<int,int>> p = ret[i];
        vector<string> vstr(n,string(n,'.'));
        
        for(int j=0;j<p.size();++j){
            vstr[p[j].first][p[j].second]='Q';
        }
        res.push_back(vstr);
    }
    return res;
}
