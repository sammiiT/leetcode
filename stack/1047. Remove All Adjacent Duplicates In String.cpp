//===類似題===
1048. Longest String Chain
2390. Removing Stars From a String

//===思路====
(*)string 可以如vector<int> 一樣, 當stack使用
-string.push_back(x)
-string.pop_back()
-string.back()
1.每次一個新的element取出時
-與stack中的top做判斷:
--如果element=stack.top, 則stack做pop, 且不將element加到stack
--如果element!=stack.top, 則將element加入stack
  
//=====
string removeDuplicates(string s) {
    string res;
    for(int i=0;i<s.size();i++){
        int remove=0;
        while(!res.empty() && res.back()==s[i]){
            remove=1;
            res.pop_back();
        }
        if(!remove) res.push_back(s[i]);
    }
    return res;

}
