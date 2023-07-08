//===類似題====
151. Reverse Words in a String
224. Basic Calculator
282. Expression Add Operators

//====思路===
(*)用stack
1.遇到運算元, 將其push到 stack
2.遇到運算子, 將stack中的運算元(2個)移出stack; 對運算子做運算
3.算完之後的新值, 再推入stack中
["4","13","5","/","+"]

+---+---+---+---                  +---+---+-                +---+------+-         
| 4 | 13| 5 |  <--push  => "/" => | 4 |   --->pop 13/5  =>  | 4 | 13/5 | <--- push(13/5)   
+---+---+---+---                  +---+---+-                +---+------+- 
    
         +---+---+-                   +--------+- 
=>"+" => |   ---> pop => 4+(13/5)  => |4+(13/5)| <--push
         +---+---+-                   +--------+- 
    
4.最後的解在stack
//===
int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for(int i=0; i<tokens.size(); i++){
        int tmp=0;
        if(tokens[i]=="+"){
            tmp = stk.top();
            stk.pop();
            tmp = stk.top()+tmp;
            stk.pop();
            stk.push(tmp);
            
        }else if(tokens[i]=="-"){
            tmp = stk.top();
            stk.pop();
            tmp = stk.top()-tmp;
            stk.pop();
            stk.push(tmp);
        }else if(tokens[i]=="*"){
            tmp = stk.top();
            stk.pop();
            tmp = stk.top()*tmp;
            stk.pop();
            stk.push(tmp);
            
        }else if(tokens[i]=="/"){//
            tmp = stk.top();
            stk.pop();
            tmp = stk.top()/tmp;
            stk.pop();
            stk.push(tmp);
        } else 
         stk.push(stoi(tokens[i]));
    }
    return stk.top();     
}

//====寫法2===
int evalRPN(vector<string>& tokens){
    stack<int> stk;
    for(string str:tokens){
        if(str=="+"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b+a);
        }else if(str=="-"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b-a);
            
        }else if(str=="*"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b*a);
        
        }else if(str=="/"){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b/a);
            
        }else{
            stk.push(stoi(str));
        }
    }
    return stk.top();
}
