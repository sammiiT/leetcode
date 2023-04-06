//===類似題===
1191. K-Concatenation Maximum Sum
126. Word Ladder II
1427. Perform String Shifts
140. Word Break II

//===思路===
1.宣告一個Stack, 其元素為string
- vector<string>

2.宣告一string, 紀錄遍歷發生的character
3.遍歷string, 如果遇到 字元, 則將字元加入 string中

4.如果遇到'(', 將string的資料push到vector<string>中; 並將string重置(reset)
- 遇到'('就重新計算 string的內容

5.如果遇到')', 依照題意, 將記錄中的string反轉, 並加上vector<string>的top, 當成新的string
-同時將vector<string>的top移除(pop_back());

(ab(cde)...                  =>  (abedc... 
  |    |                            |
  |     \                            \
   \     遇到')';將cde反轉         反轉的string加上vector<string>的back();當作新的string,繼續與後面的char做計算 ;    
   在vector<string>的back()        (*)要將back()刪除
//====
string reverseParentheses(string s) {
    vector<string> vstr;
    string tmp;

    for(int i=0; i<s.size(); ++i){
        if(s[i]=='('){
            vstr.push_back(tmp);
            tmp.clear();
        }else if(s[i]==')'){
            reverse(tmp.begin(),tmp.end());
            vstr.back() = vstr.back() + tmp;
            tmp = vstr.back();
            vstr.pop_back();

        }else{//s[i]==character
            tmp+=s[i];
        }
    }
    return tmp;        
}
