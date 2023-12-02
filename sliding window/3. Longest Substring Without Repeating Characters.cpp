//===類似題===
4. Median of Two Sorted Arrays
159. Longest Substring with At Most Two Distinct Characters
340. Longest Substring with At Most K Distinct Characters
992. Subarrays with K Different Integers
//===思路====


//======寫法1===
int lengthOfLongestSubstring(string s){
  unordered_map<char,int> m;
  int left = -1;
  int res = 0;
  
  for(int i=0; i<s.size(); i++){
    if(m.count(s[i]) && m[s[i]]>left){
      left = m[s[i]];
    }
    m[s[i]]=i;
    res = max(res,i-left);
  }
  return res;
}
//===寫法2===
1. unordered_map<char,int> //character, position(0-index) 
- 紀錄char出現的位置, 重複出現會將之前的位置覆蓋
2.遍歷數列
- i 遍歷index
- j 新數列的開始index

3.出現重複char
-if(ump.count(s[i]) && j<=ump[s[i]])
(*)情況j<ump[s[i]]  
j               i  
a   b   c   d   b   e
    \ 
 ump[s[i]] 


(*)情況j==ump[s[i]]
j     i  
a  b  a
\
 ump[s[i]]

- j=ump[s[i]]+1  索引j跳到s[i]出現的位置的下一個位置
  

int lengthOfLongestSubstring(string s){
    unordered_map<char,int> ump;
    int res=0,i,j;
    
    for(i=0,j=0; i<s.size(); ++i){
        if(ump.count(s[i]) && j<=ump[s[i]])
            j=ump[s[i]]+1;
        ump[s[i]]=i;
        res = max(res,i-j+1);
    }
    return res;  
}
