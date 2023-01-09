//===類似題====
1250. Check If It Is a Good Array
1963. Minimum Number of Swaps to Make the String Balanced
2116. Check if a Parentheses String Can Be Valid

//===思路===
(*)利用stack
(*)參考 20. Valid Parentheses.cpp 題目
(*)此題跟valid parenttheses有點不一樣, stack中可以加入')'字元
1. 先判斷 '(',如果是'('則壓入stack
2. 如果是')'或其他字元, 則做下列判斷
- 如果是字元, 則continue
- 如果stack是empty(), 則壓入stack, 一定都第一個是發生')'的情況
- 如果stack不是empty(), 判斷stack.top()是否為'('; 
如果是'('則pop stack;
如果是')',則push stack;

//=====
string helper0(string s){
    vector<pair<char,int>> stk;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            stk.push_back({'(',i});
            
        }else{//')' or character
            if(s[i]!=')') continue;
            
            if(!stk.empty()){//(
                if(stk.back().first=='(')
                    stk.pop_back();
                else
                    stk.push_back({s[i],i});
            
                
            } else if(stk.empty()){
                stk.push_back({s[i],i});
            }
        }
    }
    while(!stk.empty()){
        pair<char,int> t = stk.back();
        s.erase(s.begin()+t.second);
        stk.pop_back();
    }
    return s;
}


    string minRemoveToMakeValid(string s) {
        return helper0(s);    
    }
