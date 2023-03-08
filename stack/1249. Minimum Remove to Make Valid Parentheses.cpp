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

3.最後依據stack中的元素, 從top開始做pop, 根據top的)或(位置, 將其移除
s.erase(s.begin()+ 9), 第九個
//=====
string helper1(string s){
    stack<pair<char,int>> stk;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z') continue;
        if(s[i]=='('){
            stk.push({'(',i});
        }else{//')'
            if(!stk.empty()){
                if(stk.top().first=='(') stk.pop();
                else//')'
                    stk.push({')',i});
            }else{ stk.push({')',i}); }
        }
    }
/*    for(int i=s.size()-1; i>=0; i--){//time limit exceeded
        if(!stk.empty() && stk.top().second==i){
            stk.pop(); continue;
        }
        res = s[i] + res;
    }*/
    while(!stk.empty()){
        s.erase(s.begin()+stk.top().second);
        stk.pop();
    }
    return s;
}

string helper0(string s){
    vector<pair<char,int>> stk;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            stk.push_back({'(',i});
            
        }else{//')' or character
            if(s[i]!=')') continue;
            
            if(!stk.empty()){//(
                if(stk.back().first=='(')  stk.pop_back();//如果是'('則pop stack
                else  stk.push_back({s[i],i});//如果是')',則push stack;
            
            }else if(stk.empty()){//如果stack是empty(), 則壓入stack, 一定都第一個是發生')'的情況
                stk.push_back({s[i],i});
            }
        }
    }
    while(!stk.empty()){//最後依據stack中的元素, 從top開始做pop, 根據top的)或(位置, 將其移除
        pair<char,int> t = stk.back();
        s.erase(s.begin()+t.second);
        stk.pop_back();
    }
    return s;
}
string minRemoveToMakeValid(string s) {
        return helper0(s);    
}
//===思路2===
    string minRemoveToMakeValid(string s) {

        vector<int> st;

        int n=s.length();
        // unordered_set<int>set;

        for(int i=0;i<n;i++){
            if(s[i]=='(') 
                st.push_back(i);
            else if(s[i]==')'){
                if(st.empty()) 
                    s[i]='#';
                else st.pop_back();
            }
        }
        for(auto i:st)
            s[i]='#';

        string ans="";
        for(auto i:s){
            if(i!='#') 
                ans+=i;
        }

        return ans;
    }
//===思路3===
    string minRemoveToMakeValid(string s) {
        string res;
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (st.empty()) s[i] = '*';
                else st.pop();
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*'; st.pop();
        }
        for (char c : s) {
            if (c != '*') res += c;
        }
        return res;
    }
