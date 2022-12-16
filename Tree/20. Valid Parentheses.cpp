//===類似題===
21. Merge Two Sorted Lists
22. Generate Parentheses
32. Longest Valid Parentheses
301. Remove Invalid Parentheses
//===思路===
1.將(,[,{放入stack中
2.如果接下來的字元,),],}可以對應stack中的元素 pop出來, 代表可成對
3.最後若stack是empty(), 代表valid.
  
(*)如果stak中沒有element,則stack.top()會錯誤, 
所以if((stk.top()=='('&&s[i]==')')||(stk.top()=='['&&s[i]==']')||(stk.top()=='{'&&s[i]=='}'))
沒有任何element在stack中, 則stk.top()造成執行錯誤
在前面要加上 if(stk.empty()) return false;

//=====
 bool helper0(string s){
        stack<char> stk;
        for(int i=0; i<s.size(); i++){            
            if(s[i]=='('||s[i]=='['||s[i]=='{'){//push
                stk.push(s[i]);
            }else{//check
                if(stk.empty()) return false;
                if((stk.top()=='('&&s[i]==')')||(stk.top()=='['&&s[i]==']')||(stk.top()=='{'&&s[i]=='}')) 
                    stk.pop();
                else return false;
            }
        }
        return stk.empty()?true:false;
}

bool isValid(string s) {
        return helper0(s);
}
