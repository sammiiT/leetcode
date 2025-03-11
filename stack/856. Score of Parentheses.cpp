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

#=== 寫法3 ===
遇到 '('進入下一層
count+=dfs('(')

如果(')') return 1;
如果(')' && [i-1]==')') return count*2;
    
int dfs2(string& s, int& i){
    int count=0;
    while(i<s.size()){
        if(s[i]=='('){
            count+=dfs2(s,++i);
        }else{
            if(s[i]==')'){
                if(s[i-1]=='(') {
                    ++i;
                    return 1;
                } else {//s[i-1]==')'
                    ++i;
                    return count*2;
                }
            }
        }
    }
    return count;
}

    
