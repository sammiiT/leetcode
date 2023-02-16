//===類似題===
243. Shortest Word Distance
266. Palindrome Permutation
438. Find All Anagrams in a String
2273. Find Resultant Array After Removing Anagrams
//===思路===
1.建立一陣列,有26個元素, 因為有26個字母
2.遍歷string s, 將每個字母出現的次數記錄在陣列中
3.遍歷string t, 將出現的字元與對應陣列的個數做比較(出現一次減一次)
4.如果對應的數值小於0,代表有多的,或沒出現過的字母;回傳false
//====
bool helper0(string s, string t){
  if(s.size()!=t.size()) return false;
  int m[26]={0};
  for(char a:s) m[a-'a']++;
  for(char a:t){
    if(--m[a-'a']<0) return false;
  }
  return true;
}
bool isAnagram(string s, string t) {
  return helper0(s, t);
}

//===思路2===
1.將s和t作排列
2.比較s和t是否相等
//=====
bool helper1(string s, string t){
    if(s.size()!=t.size()) return false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return (s==t);
}
