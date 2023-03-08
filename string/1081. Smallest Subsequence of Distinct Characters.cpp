//===類似題===
1079. Letter Tile Possibilities
1673. Find the Most Competitive Subsequence
316. Remove Duplicate Letters
//===思路===
(*)同316. Remove Duplicate Letters
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
-not change the order =>subsequence
-substring

-subsequence: order不改變; 從陣列中挑選出來的元素 "order不改變"
-subarray: 從陣列中挑選出的元素, "order不變"且"連續"

遍歷數列, 因為遍歷數列一定會按照順序  
dynamic programming也是遍歷數列, 所以按照順序

//====
string smallestSubsequence(string s) {
    int visited[256]={0};
    unordered_map<char,int> mp;//character, count;
    string res = "";
    
    for(char c:s) mp[c]++;
    for(int i=0; i<s.size(); i++){
        mp[s[i]]--;
        if(visited[s[i]]) continue;
        while(res.size() && res.back()>=s[i] && mp[res.back()]){
        //while(res.size() && res.back()>=s[i] && mp[s[i]]){//要被check的,是mp[res.back()]
        //while(res.size() && res.back()>s[i] && mp[s[i]]){//要被check的,是mp[res.back()]
        //visited[s[i]] = 0;//移除的是res.back, 所以此描述會錯誤            
            visited[res.back()]=0;
            res.pop_back();
        }
        visited[s[i]]=1;
        res.push_back(s[i]);
    }
    return res;
}
