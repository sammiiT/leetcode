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
