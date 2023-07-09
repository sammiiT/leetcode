//===類似題===
21. Merge Two Sorted Lists
22. Generate Parentheses
32. Longest Valid Parentheses
301. Remove Invalid Parentheses
//===思路====
(*)用stack
1.(,[,{和},])一定要對應出現 ()[]{}, {[()]}
2.出現 ([{就push進 stack
3.非 ([{就和stack.top做比較, 如果有成對, 就stack.pop
  如果不成對, 即return false;
       
4.最後比較完, 還有一條件判斷, 因為有[[[ ]] 狀況發生
  stk.empty()?true:false;
5.  stack中的element都清空, 才是滿足條件的解.
                      
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
                //else stk.push(s[i]); 
                else return false;
            }
        }
        return stk.empty()?true:false;
     }
//----寫法2
bool helper1(string s){
    stack<char> stk;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{') stk.push(s[i]);
        else {//),],}
            
            if(!stk.empty() && ((s[i]==')'&&stk.top()=='(')||(s[i]=='}'&&stk.top()=='{')||(s[i]==']'&&stk.top()=='[')) ){ 
                stk.pop();
            }
            else {//stk.empty()
                return false;
            }
        }
    }
//    return true;//[[[ ]]若出現此排列,會錯誤
    return stk.empty()?true:false;
}
//----寫法3
bool helper2(string s){
    stack<char> stk;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{') stk.push(s[i]);
        else{
            if(stk.empty() && (s[i]==')'||s[i]==']'||s[i]=='}')) return false;//empty()=> 回傳false
            if((stk.top()=='('&&s[i]==')') ||(stk.top()=='['&&s[i]==']')||(stk.top()=='{'&&s[i]=='}')) stk.pop();//=>兩個可以匹配
            else return false;//兩個無法互相匹配
        }
    }
    return stk.empty()?true:false;//[[[[]]判斷; 保險
}                  
bool isValid(string s) {
    return helper1(s);
//        return helper0(s);
}

//----寫法4
bool isValid(string s) {
  stack<char> stk;
  for(int i=0;i<s.size();++i){
      if(!stk.empty()&& ( (stk.top()=='('&&s[i]==')') || (stk.top()=='('&&s[i]==')') || (stk.top()=='('&&s[i]==')') )){
        stk.pop();
      }else{
        stk.push(s[i]);
      }
  }
  return (stk.size()==0);
}
