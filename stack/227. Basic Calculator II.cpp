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

(*)tip: 
1.負數的to_string(x)會失真;
- int a = -1;
  to_string(a); //結果會有一個"-"

2.stack用integer表示, 不存(push)運算子,將數值與運算子分開 
3.遇到*或/運算子, 則必須先運算, 將stk.top的數值取出做運算(與當下的數值做運算)

4+5*               4+5*6
+---+---+---       +---+---+---                                   +---+---+---
| 4 | 5 |    ===>  | 4 |   ---> 5 pop出來, 5*6算完再push回去  ===> | 4 | 30  <---算完push回去
+---+---+---       +---+---+---                                   +---+---+---
  
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
(*)先將運算元,運算子分開, 並放到同一個vector<string>的陣列中
- string s = "3+2*24";
-- vector<string>  =>  "3","+","2","*","24"
===> 這個算法會在leetcode出現stoi terminate, 但其他compiler不會有此問題
int calculate(string s) {
   stack<int> stk;
   vector<string> cal;
   enum{ADD,SUB,MUL,DIV};
   int action = ADD;
   int res =0;
   
   string p;//先將運算元,運算子分開, 並放到同一個vector<string>的陣列中
   for(int i=0;i<s.size();i++){
      if(i==s.size()){
         cal.push_back(p);
         break;
      }
      if(s[i]<'0'||s[i]>'9'){
         string tmp;
         tmp+=s[i];
         cal.push_back(p);
         p.clear();
         cal.push_back(tmp);
      }else{ p+=s[i]; }
   }
   
   for(int i=0; i<cal.size(); i++){
      if(cal[i]=="+"){ action = ADD;
      }else if(cal[i]=="-"){ action = SUB;
      }else if(cal[i]=="*"){ action = MUL;
      }else if(cal[i]=="/"){ action = DIV;
      }else{
         if(action==ADD) stk.push(stoi(cal[i]));
         else if(action==SUB) stk.push(stoi(cal[i])*(-1));
         else if(action==MUL) stk.top() = stk.top()*stoi(cal[i]);
         else if(action==DIV) stk.top() = stk.top()/stoi(cal[i]);
      }
   }
   int res = 0;
   while(!stk.empty()){
      res+=stk.top();
      stk.pop();
   }
   return res;
}

//=== 思路3 ====
int calculate(string s) {

    stack<long> digit;
    stack<char> optr;
    
    long val = 0;
    optr.push('+');
    for(int i=0; i<s.size(); ++i){
        if(s[i]>='0'&&s[i]<='9'){
            val = val*10+s[i]-'0';
        } else if(s[i]==' '){//空格情況
        } 
        else {//+,-,*,/
            if(optr.top()=='*'){
                digit.top() = digit.top()*val;
            } else if(optr.top()=='/') {
                digit.top() = digit.top()/val;
            } else if(optr.top()=='+') {
                digit.push(val);
            } else if(optr.top()=='-') {
                digit.push(val*(-1));
            }
            val = 0;
            optr.push(s[i]);//每次operator都疊加上去, 不用pop, 因為運算過程中不會影響 
        }
    }

//最後一個數值
    if(optr.top()=='*'){
        digit.top() = digit.top()*val;
    } else if(optr.top()=='/') {
        digit.top() = digit.top()/val;
    } else if(optr.top()=='+') {
        digit.push(val);
    } else if(optr.top()=='-') {
        digit.push(val*(-1));
    }
    val = 0;

    while(!digit.empty()){
        val+=digit.top();
        digit.pop();
    }
    return val;
}
#==== 寫法3 ===

int calculate(string s) {

    stack<long> stk;
    stack<char> stkop;
    long sum = 0;
    int sign = 1;
    s=s+'#';

    for(char c:s){
        if(c=='+'){
            while(!stkop.empty()){
                char op = stkop.top();stkop.pop();
                int val = stk.top();stk.pop();
                sum=(op=='*')?(val*sum):(val/sum);
            }
            stk.push(sum*(sign));
            sum=0;
            sign=1;    
        
        }else if(c=='-'){
            while(!stkop.empty()){
                char op = stkop.top();stkop.pop();
                int val = stk.top();stk.pop();
                sum=(op=='*')?(val*sum):(val/sum);
            }
            stk.push(sum*(sign));
            sum=0;
            sign=-1;

        }else if(c==' '){
            //do nothing
        }
        else if(c=='#'){
            while(!stkop.empty()){
                char op = stkop.top();stkop.pop();
                int val = stk.top();stk.pop();
                sum=(op=='*')?(val*sum):(val/sum);
            }
            stk.push(sum*(sign));
            sum=0;
            sign=1;            

        }else if(c=='*'){
            while(!stkop.empty()){
                char op = stkop.top();stkop.pop();
                int val = stk.top();stk.pop();
                sum=(op=='*')?(val*sum):(val/sum);
            }
            stkop.push('*');
            stk.push(sum*sign);
            sum=0;
            sign=1;
        
        }else if(c=='/'){
            while(!stkop.empty()){
                char op = stkop.top();stkop.pop();
                int val = stk.top();stk.pop();
                sum=(op=='*')?(val*sum):(val/sum);
            }
            stkop.push('/');
            stk.push(sum*sign);
            sum=0;
            sign=1;
        
        }else{
            sum=sum*10 + c-'0';
        }    
    }

    sum=0;
    while(!stk.empty()){
        sum+=stk.top();
        stk.pop();
    }
    return sum;
}
