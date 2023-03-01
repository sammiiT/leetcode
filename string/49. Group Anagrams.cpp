//===類似題===
50. Pow(x, n)
249. Group Shifted Strings
2273. Find Resultant Array After Removing Anagrams
2514. Count Anagrams
//===思路====


//=======
vector<vector<string>> groupAnagrams(vector<string>& strs){
  unordered_map<string,vector<int>> m;
  vector<vector<string>> res;
  for(int i=0;i<strs.size();i++){//for(string a:strs){
      string a = strs[i];
      sort(a.begin(),a.end());
      m[a].push_back(i);
  }
  for(auto a:m){
      vector<int> x = a.second;
      vector<string> s;
      for(int i=0;i<x.size();i++)
          s.push_back(strs[x[i]]);
      res.push_back(s);
  }
  return res;
}
//====failed===
(*)沒有判斷到每一個character只能出現一次
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<int,vector<int>> m;
    vector<vector<string>> res;
    for(int i=0;i<strs.size();i++){
        int mask=0;
        for(char x:strs[i])
            mask = mask | (1<<(x-'a'));
        m[mask].push_back(i);
    }
  
    for(auto a:m){
        vector<int> x = a.second;
        vector<string> s;
        for(int i=0; i<x.size(); i++){
            s.push_back(strs[x[i]]);
        }
        res.push_back(s);
    }
    return res;

}
