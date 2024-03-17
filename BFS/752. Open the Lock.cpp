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
  
- 每一層用dirs來判斷; vector<int> dirs = {-1,1}; //每一層有兩個元素
-vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};//每一層有四個元素

(*)下一層的每一個結果(每一種可能) , 全部都被當作一步
0, 0, 0, 0 => 1,0,0,0
           => 9,0,0,0
           => 0,1,0,0
           => 0,9,0,0
           => 0,0,1,0
           => 0,0,9,0
           => 0,0,0,1
           => 0,0,0,9
下一層的每一個結果, 共8個, 從"上一層"衍生出的每一種可能, 都被視為一步   

(*)所有的結果當中, 會有一個結果先到達target, 此target所回傳的 步數, 為解

target = 0,0,0,8
0,0,0,0 => xxxx
           ....
           0009 => ****
                   ....
                   0008 =>target
第一層     第二層   第三層 ; 第三層中有target

(*)
a0所產生的BFS可能結果為{a10},{a11},{a12},{a13}   
    +------------+
   /               \
[{a0},{b0}] [{a10},{a11},{a12},{a13}] [{b10},{b11},{b12},{b13}]  
        \                            /
         +--------------------------+
b0所產生的BFS可能結果為 {b10},{b11},{b12},{b13}
每一個 "結果" 所對應的visited, 都會影響到 後面BFS的結果

(*)跟word ladder做比較
-word ladder 每變一個字母, 一直到整個單字存在於wordDictionary; 算一種可能
-open lock 每變一個數字, 都是一種可能  
  
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
//====寫法2(類似)===
int helper2(vector<string>& deadends, string target) {
    unordered_set<string> dends(deadends.begin(),deadends.end());
    unordered_set<string> visited;
    vector<int> dirs={1,-1};//({1,-1});
    queue<string> q;
    int res=0;

    if(dends.count("0000")) return -1;
    if(target=="0000") return 0;

    q.push("0000");
    visited.insert("0000");

    while(!q.empty()){
        res++;
        for(int i=q.size(); i>0; --i){
            string p = q.front();q.pop();
            for(int j=0;j<p.size();++j){
                for(int dir:dirs){
                    string str = p;
                    str[j]=(str[j]-'0'+10+dir)%10+'0';
                    if(str==target) return res; 
                    //if(!visited.count(t)&&!dends.count(t)) q.push(t);上面是用這種寫法
                    if(dends.count(str)||visited.count(str)) continue;
                    q.push(str);
                    visited.insert(str);
                }
            }                
        }
    }
    return -1;
}
