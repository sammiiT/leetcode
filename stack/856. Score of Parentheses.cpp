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
//===思路2===
(*) dfs

int dfs(string& s, int& i, int& level){
    int sum =0;
    while(i<s.size()){
        if(s[i]=='('){
            level=0;
            sum = sum + dfs(s,++i,level);
        } else {//s[i]==')'
            if(level>0) sum = sum*2;
            else sum+=1;
            level++;
            return sum;
        }
        ++i;
    }
    return sum;
}

int scoreOfParentheses(string s) {
    int i = 0;
    int level =0;
    return dfs(s,i,level);        
}
