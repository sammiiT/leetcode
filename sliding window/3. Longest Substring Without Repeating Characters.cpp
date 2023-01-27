//===類似題===
4. Median of Two Sorted Arrays
159. Longest Substring with At Most Two Distinct Characters
340. Longest Substring with At Most K Distinct Characters
992. Subarrays with K Different Integers
//===思路====


//======
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
