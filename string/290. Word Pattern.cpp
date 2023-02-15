//===類似題===
291. Word Pattern II
More challenges
291. Word Pattern II
//===思路1====
(*) 用unordered_map建立pattern和string之間的映射

//====



//===思路2===
(*)用兩個unordered_map,來判斷pattern和string之間映射"順序"是否相同
-如果用映射"個數"會錯誤
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
      
/* //紀錄 "個數",會錯誤,因為沒有考慮到順序    
      m1[pattern[i]]++;
      m2[word]++;
*/
  }
  return (i==n);
}

pattern="aba";
s="dog cat cat";
=>計算到第二個,m1[a]=1,m1[b]=1; m2[dog]=1,m2[cat]=1;
=>當計算到第三個 m1[a]=1,m2[cat]=1;但m1[a]對應的必須是dog,而不是cat.
