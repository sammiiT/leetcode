#=== more challenge ===
30. Substring with Concatenation of All Words
567. Permutation in String
632. Smallest Range Covering Elements from K Lists

#=== 思路 ===
(*) sliding window
(*) 判斷過程中, 會有超出原有letter數量的情況
所有的 大小字母的ascii碼, 在128數值內; 建立
vector<int> letters(128,0);  
紀錄目標(t)字母數量
被比較(s)


string minWindow(string s, string t) {
  vector<int> letters(128,0);
  int cnt=0, left = 0, minLeft=-1,len=INT_MAX;
  for(char c:t) letters[c]++;
  for(int i=0;i<s.size();++i){
    if(--letters[s[i]]>=0) cnt++;//多餘的不影響, 仍代表滿足條件
    while(cnt==t.size()){
        if(len>i-left+1){
          len = i-left+1;
          minLeft=left;
        }
        if(++letters[s[left]]>0) cnt--;
        left++;
    }
  }
  return minLeft==-1?"":s.substr(minLeft,len);
  
}
