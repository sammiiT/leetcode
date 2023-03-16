//===類似題===
857. Minimum Cost to Hire K Workers
1271. Hexspeak
1700. Number of Students Unable to Eat Lunch
2452. Words Within Two Edits of Dictionary
//===思路====


//======

int scoreOfParentheses(string s) {
    int res = 0;
    stack<int> stk;
    for(char c:s){
        if(c=='('){
            stk.push(res);
            res = 0;        
        }else{//c==')'
            res = stk.top() + max(res*2,1);
            stk.pop();
        }
    }
    return res;
}
