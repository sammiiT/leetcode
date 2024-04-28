/*
bool helper0(string s, vector<string>& wordDict){
    unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
    vector<int> dp(s.size(),0);
    
    dp[0]=true;
    
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<=i; j++){//  j<=i  => 會發生i-j=0的情況
            if(wordSet(s.substr(j,i-j)))
        }
    }
}
*/


bool helper0(string s, vector<string>& wordDict){
  unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
  vector<bool> dp(s.size()+1,0);//+1是為了(i-j)計算, 為了記錄下一個seperation 的start
  dp[0]=true;
  
  for(int i=0; i<dp.size(); i++){
//j可視為string的每一個index; i是下一個strat的index,且用來運算每一個seperate string的長度    
    for(int j=0; j<i; j++){
                               //了解s.substr()使用, 間接可以解釋為什麼dp(s.size()+1) 
      if(dp[j] && wordSet.count(s.substr(j,i-j))){
        dp[i]=true;
        break;
      }
    }
  }
  return dp.back();
}

bool wordBreak(string s, vector<string>& wordDict){
  return helper0(s,wordDict);
}

//====思路2 會造成Time Limited Exceeded====
(*)DFS 寫法, 會Time Limited Exceeded

bool dfs(string& s,  int start, unordered_set<string>& ust){
    if(start==s.size()) return true;

    bool ret = false;
    for(int i=start; i<s.size(); ++i){
        if(ust.count(s.substr(start,i-start+1))) {//wordDict中有 cat, cats 
            ret = dfs(s, i+1, ust);               //上述造成不一樣的路徑
            if(ret==true) {
                return true;
            }
            else continue;
        }        
    }
    return ret;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> ust(wordDict.begin(),wordDict.end());
    vector<int> memo(s.size(),-1);
    return dfs(s,0,ust);
}

//===思路3 優化修正====
(*)DFS + memory, 可在時間內解完

bool dfs(string& s,  int start, unordered_set<string>& ust, vector<int>& memo){
    if(start==s.size()) return true;
    if(memo[start]!=-1) return memo;//有點像其他題目的 visited 陣列
    
    bool ret = false;
    for(int i=start; i<s.size(); ++i){
        if(ust.count(s.substr(start,i-start+1))) {//wordDict中有 cat, cats 
            ret = dfs(s, i+1, ust, memo);               //上述造成不一樣的路徑
            if(ret==true) {
                memo[start]=true;
                return true;
            }
            else continue;//下一層的所有結果, 是false
        }        
    }
    memo[start]=false;
    return ret;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> ust(wordDict.begin(),wordDict.end());
    
    vector<int> memo(s.size(),-1);
    return dfs(s,0,ust,memo);
}

//=== 如何計算出 "解"的個數====
(*)紀錄解的個數?? 怎麼寫?
(*)bool 回傳值: 有或沒有
-? int 回傳值, 紀錄當下層有幾個解, 往上層推導, 並做累加; memo就用來記錄當下層的解總數, 來防止重複計算
- 用memo做防止重複運算機制,有點像BFS中的防止機制
- DFS的防止是在下一層做判斷,再回傳;  BFS的防止機制是在當下層就把錯誤排除在外(不然會time_limited_exceeded)

int dfs(string& s, 
        int start, 
        unordered_set<string>& ust, 
        vector<int>& memo,
        int& res){
    if(start==s.size()) return 1;//一個解,匹配成功;所以回傳1  
    if(memo[start]!=-1) return memo[start];
    
    int ret = 0;
    for(int i=start; i<s.size(); ++i){
        string str = s.substr(start,i-start+1);
        if(ust.count(str)){
            ret += dfs(s,i+1,ust,memo,res);
        }
    }
    memo[start] = ret;
    return ret;
}






















