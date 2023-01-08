//===類似題===
228. Summary Ranges
224. Basic Calculator
282. Expression Add Operators
772. Basic Calculator III
//===思路===
(*)利用stack做運算
1. 遇到+,-,*,/ 則記錄, 給下一個數值配對做計算
2. 若數值前一個符號是"+", 數值直接push到stack 
   若數值前一個符號是"-", 數值乘上(-1), push到stack
  若數值前一個符號是"*", 將stack的top乘上數值
  若數值前一個符號是"/", 將stack的top除以數值

3.因為數值有可能是多位數, 所以遇到數值時, 要繼續往下找, 找到非數值才停止

//=====
int helper0(string s) {
    stack<int> stk;
    int res = 0;
    enum Action{ADD,SUB,MUL,DIV};
    Action action =ADD;
//    stk.push(0);
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'){ action = ADD;
        }else if(s[i]=='-'){ action = SUB;
        }else if(s[i]=='*'){ action = MUL;
        }else if(s[i]=='/'){ action =DIV;
        }else if(s[i]==' '){
        }else{//number
            int j = i;
            string tmp;
            do{//因為數值有可能是多位數, 所以遇到數值時, 要繼續往下找, 找到非數值才停止
                tmp+=s[j];
                j++;
            }while(j<s.size() && s[j]>='0' && s[j]<='9');
            i=(j-1);//退回,給下一個for運算
                    
            if(action==ADD) stk.push(stoi(tmp));
            else if(action==SUB) stk.push((-1)*stoi(tmp));
            else if(action==MUL) stk.top()=stk.top()*stoi(tmp);
            else if(action==DIV) stk.top()=stk.top()/stoi(tmp);
        }
    }
    while(!stk.empty()){
        res+=stk.top();
        stk.pop();
    }
    return res;
}
int calculate(string s) {
    return helper0(s);    
}

//====思路2====
