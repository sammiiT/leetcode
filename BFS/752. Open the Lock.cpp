//===類似題===
1326. Minimum Number of Taps to Open to Water a Garden
2368. Reachable Nodes With Restrictions
//===思路===
(*)BFS: 窮舉滿足條件的元素 , 並將此元素推入queue中
(*)每一個level都算轉換一次;如何區分每一個level(層)
- 用for loop區分每一層的所有元素
-不能用 for(int k=0;k<q.size();++k), 因為下面在計算時,會將滿足條件的元素放入q,所以k<q.size()的每一次的size都不一樣
-用for(int k=q.size();k>0;--k); 因為k一開始就固定了, 下面新增到queue的元素算下一個level
-t[j]=(p[j]-'0'+10+dir)%10+'0'; //+10的原因是因為dir有"+"有"-", 為了避免相減之後,小於1, 所以要加10
  
  
//====
int openLock(vector<string>& deadends, string target) {
  unordered_set<string> dends(deadends.begin(),deadends.end());
  unordered_set<string> visited;
  if(target=="0000") return 0;
  if(dends.count("0000")) return -1;
  int res = 0;
  vector<int> dirs{1,-1};
  queue<string> q;
  q.push("0000");
  visited.insert("0000");
  
  while(!q.empty()){
      res++;//每一個level記數一次
      for(int i=q.size(); i>0; --i){
          string p = q.front();q.pop();
          for(int j=0; j<p.size(); ++j){
              for(int dir:dirs){
                string t = p;
                t[j]=(p[j]-'0'+10+dir)%10+'0';
                if(t==target) return res;
                if(!visited.count(t)&&!dends.count(t)) q.push(t);
                visited.insert(t);
              }
          }
      }
  }
  return -1;
}

