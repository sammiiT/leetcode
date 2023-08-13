//===類似題===
291. Word Pattern II
More challenges
291. Word Pattern II
//===思路1====
(*) 用unordered_map建立pattern和string之間的映射
(*) unordered_map<char,string>; character對應string的map
unordered_map<string,char>; string對應character的 map

(*)istringstream和ostringstream使用
  
(*)以pattern的char為依據做遍歷.
1.先建立 string的 substring pattern 到 vector<string>中; 再與pattern string做比較
2.遍歷 pattern來判斷對應的 string

(@1)狀況一
  a      b      a
   \      \      \
    dog    cat    fish   

(@2)狀況二
  a      b      c
   \      \      \
    dog    cat    dog   


//====
bool wordPattern(string pattern, string str) {
  vector<string> words;
  istringstream in(str);
  unordered_map<char,string> mpcs;
  unordered_map<string,char> mpsc;
  
  for(string word;in>>word;){ words.push_back(word);}
  if(pattern.size()!=words.size()) return false;//"aaa" ; "aa aa aa aa"
  
  for(int i=0; i<pattern.size(); ++i){
    if(mpcs.count(pattern[i])) {
      if(mpcs[pattern[i]]!=words[i]) return false;//如果原來有對應string的char, 對應了新的string  (@1)
    } else {//!mpcs.count(pattern[i])
      if(mpsc.count(words[i])) return false;// 新的char對應的string不存在;但string在之前有對應的char (@2)
      mpcs[pattern[i]]=words[i];
      mpsc[words[i]]=pattern[i];
    } 
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
