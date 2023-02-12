//====類似題=====
395. Longest Substring with At Least K Repeating Characters
471. Encode String with Shortest Length
726. Number of Atoms
1087. Brace Expansion

//===思路===
1.設定兩個stack; 一個存個數, 一個存string

   stkNum          stkStr   
  +-----+         +-----+
  |     |      -->| str3|
  |-----|    /    |-----|
  |  n3 |---/  -->| str2| 
  |-----|    /    |-----|
  |  n2 |---/  -->| str1|
  |-----|    /    |-----|
  |  n1 |---/     |     |  
  +-----+         +-----+
下一個要重複個數    要依據前一個數字來重複string  

ex:
abs3[a2[c]]
第一次放到stkNum =3 ;第一次放到stkStr = abs
3並不會重複abs, 3會重複a2[c]
stkNum =i 會對應到 stkStr = i+1

2.遇到'[', 把數字push到 stkNum, 把字串push到stkStr;
此時字串是依據前一個數字重複, 不是當下的數字重複

3.遇到']',將數字從stkNum pop出來, 那pop出來的數字是當下"尚未push到stkStr"的字串需要重複的字數
將當下字串重複過後, 加到stkStr的top中; 準備為stkNum的top做準備
  
4. "["代表要push, "]"代表要pop  
-]會pop成最後議需要的string.  
  
(*)如果是string是空, 也一樣可以push至stack;會在stack中占用一個位置  
(*)stack pop執行, 用stk.empty()來判斷是否為空, 可以將所有在stack中的element取出
若用for(int i=0;i<stk.size();i++) 會無法取出所有的element,沒辦法取出最初push的那一個

(*)如果stack本身為空, 用stk.top()會出錯
//=====
string helper0(string s) {
    stack<int> stkNum;
    stack<string> stkStr;
    string t="";
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt = cnt*10 + s[i]-'0';        
            
        }else if(s[i]=='['){
            stkNum.push(cnt);
            stkStr.push(t);
            t.clear();
            cnt = 0;
        }else if(s[i]==']'){
                int p = stkNum.top();stkNum.pop();
                for(int i=0;i<p;i++){
                    stkStr.top() = stkStr.top()+t;
                }
                t = stkStr.top(); stkStr.pop();
/*            int p = stkNum.top();stkNum.pop();
            string q;
            for(int i=0;i<p;i++){ q+=t; }
            stkStr.top()+=q;
            t = stkStr.top();
            stkStr.pop();*/
        }else {//character
                t+=s[i];
        }
    }
    return t;
}

string decodeString(string s) {
  return helper0(s);
}
