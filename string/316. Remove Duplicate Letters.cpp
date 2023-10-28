//===類似題===
317. Shortest Distance from All Buildings
2030. Smallest K-Length Subsequence With Occurrences of a Letter

//====思路====
(*)"解"用新建,不用in-place
1.建立map,紀錄每一個character出現的次數
2.建立visited, 紀錄運算中的"解", "是否出現過"
    
3.判斷當下的charater是否小於之前的character ;(smallest in lexicographical order)
-如果小於,就刪除
-- bc a => a  (刪除bc)

4.判斷當下的character是否在"解"中有出現; 
-如果有,則不加入"解"
-- abcd a => abcd (a出現過,不加入)

(*)
不能排列的題目描述:
-not change the order
-substring
  
遍歷數列, 因為遍歷數列一定會按照順序  
dynamic programming也是遍歷數列, 所以按照順序

(*)
leetcode
=>ltcode (x)
=>letcod (o)
    
//=======
"cbacdcbc"
string removeDuplicateLetters(string s) {
    int mp[256]={0};
    int visited[256]={0};
    string res="0";
    
    for(int i=0; i<s.size(); i++) mp[s[i]]++;
    for(int i=0;i<s.size();i++){
        m[s[i]]--;
        if(visited[s[i]]) continue;
        
        while(s[i]<res.back() && mp[res.back()]){//就算前面刪除了,後面還有出現: mp[res.back()]
            visited[res.back()]=0;
            res.pop_back();
        }
        res.push_back(s[i]);//沒出現的character放到解中
        visited[s[i]]=1;//將放到解中的character設定為 已出現過"
    }
}
