//===類似題===
291. Word Pattern II
//===思路1====
(*) 用unordered_map建立pattern和string之間的映射

(*)1對1
- x對y => 1對1
- y對x => 也必須是1對1
- 必須用第三個"z"來作為"x"和"y"相互1對1對應的變數
- pattern和string分別是"x"和"y", unordered_map<T,int>中的int就是 "z"

(*)pattern.size()和vector<string> 必須個數相同
-先判斷string中的子string

//====
bool wordPattern(string pattern, string s) {
  istringstream in(s);
  unordered_map<char,int> mpchar;
  unordered_map<string,int> mpstr;
  vector<string> tmp;
  
  for(string word;in>>word;) tmp.push_back(word);
  if(tmp.size()!=pattern.size()) return false;
  
  for(int i=0; i<pattern.size(); ++i){
    if(!mpchar.count(pattern[i])&&!mpstr.count(tmp[i])){
        mpchar[pattern[i]]=i+1;
        mpstr[tmp[i]]=i+1;
        continue;
    }
    if(mpchar[pattern[i]]!=mpstr[tmp[i]]) return false;
  }
  return true;
}


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

