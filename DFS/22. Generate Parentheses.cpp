//===類似題===
23. Merge k Sorted Lists
17. Letter Combinations of a Phone Number
2116. Check if a Parentheses String Can Be Valid

Score of Parentheses
Valid Parenthesis String 
Remove Invalid Parentheses
Different Ways to Add Parentheses
Valid Parentheses
Longest Valid Parentheses

//===思路===
(*) DFS算法, 可列出所有組合.
  
(*)n表示,有n個left 和n個right
(*)每一次執行都會用到left,right; 所以要left-1或right-1
(*)過程中, left剩下的個數必須少於right個數; 
- 如果(left> right) 表示left剩餘的個數 大於 right剩餘的個數; 代表出現 )(
-- ) , left剩下3個, right剩下2個;所以返回不繼續執行下去
-如果left剩下0個且 right剩下0個, 代表已經完成valid parentthess; 將一組解帶入

(*)如果尚未執行完,就繼續遞迴執行

//=====

void helper(int left, int right, string out, vector<string>& res){
    if(left>right) return;

    if(left==0 && right==0) res.push_back(out);
    else{
        if(left>0) helper(left-1,right,out+'(',res);
        if(right>0) helper(left,right-1,out+')',res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    helper(n,n,"",res);
    return res;
}
