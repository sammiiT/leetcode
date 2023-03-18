//===類似題===
922. Sort Array By Parity II
1963. Minimum Number of Swaps to Make the String Balanced
//===思路===
(*)用stack計算,遍歷string, 依序判斷每一個character

1. 遇到'(' 就push至stack中
2. 遇到')', 判斷stack.top()是否為'('
- 如果是'(', 將top()做 pop()
- 如果是')', 將當下的character;push至stack

3.最後stack.size() 就是解

//=======
int minAddToMakeValid(string s) {
        stack<char> stk;
        for(char a:s){
            if(a=='(') stk.push(a);
            else{//')'
                if(!stk.empty()){
                    if(stk.top()=='(') stk.pop();
                    else stk.push(')');
                } else //stk.empty()
                    stk.push(')');
            }
        }
        return stk.size();
}
