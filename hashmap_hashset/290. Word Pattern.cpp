//===類似題===
291. Word Pattern II
More challenges
291. Word Pattern II
//===思路1====
(*) 用unordered_map建立pattern和string之間的映射

//====



//===思路2===
(*)用兩個unordered_map,來判斷pattern和string之間映射個數是否相同
//====
bool wordPattern(string pattern, string str) {
  unordered_map<char,int> m1;
  unordered_map<string,int> m2;
  
  int n = pattern.size();
  int i =0;
  istringstream in(str);//會用空格區隔開每一個string
  
  for(string word; in>>word; i++){
      if(i>=n || m1[pattern[i]]!=m2[word]) return false;
      m1[pattern[i]]=i+1;
      m2[word]=i+1;
  }
  return (i==n);
}
