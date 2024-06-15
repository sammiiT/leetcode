//=== more challenge ===
2919. Minimum Increment Operations to Make Array Beautiful
2836. Maximize Value of Function in a Ball Passing Game
1950. Maximum of Minimum Values in All Subarrays

//===思路===
(*)之前stack都是儲存陣列中的數值
此提示儲存陣列index

int longestValidParentheses(string s) {
    int n = s.size();
    stack<int> stk;
    int res = 0;
    int start = 0;
  
    for(int i=0; i<n; ++i){
        if(s[i]=='('){
            stk.push(i);        
        } else { //s[i]==')'
            if(s.empty()){
              start = i+1;//不對stack做push,所以出現連續的')', 就會一直更新start
            }else{
                stk.pop();//先將'(' pop, 以下再對其做長度運算
                res = stk.empty()? max(res,i-start+1):max(res,i-stk.top());
            }
        }
    }
    return res;
    

}
