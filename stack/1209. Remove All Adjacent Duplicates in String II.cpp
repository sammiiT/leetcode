//===類似題===
1208. Get Equal Substrings Within Budget
1047. Remove All Adjacent Duplicates In String
2197. Replace Non-Coprime Numbers in Array

//===思路====
(*)用stack概念
(*)vector<T> 可以作為陣列使用, 也可以作為stack使用.
  vec.push_back()
  vec.pop_back()

1.定義stack, 元素為pair<int,char> , <個數,字元> 
2.邊界 stk{{0,'#'}} 
3.遍歷陣列時, "都跟最後一個做比較判斷", 如果不相同, 就新增pair元素,推到stack
4."跟最後一個比較", 如果字元相等, stack的top內容做+1;
5.+1後如果等於條件(個數k), 則將stack.top做pop
6.依據stack中的內容, 建立題目要的string

  
(*)跟最後一個做判斷 ==> 用stack
//======
string helper1(string s, int k){
    string res;
    vector<pair<char,int>> stk;
    stk.push_back({'@',0});
    for(int i=0; i<s.size(); i++){
        if(stk.back().first!=s[i]){
            stk.push_back({s[i],1});
        }else{//stk.back().first==s[i]
            if(++stk.back().second==k) stk.pop_back();
        }
    }
    while(!stk.empty()){//也可以用append; res.append(stk.back().second,stk.back().first);
        string t(stk.back().second,stk.back().first);
        res = t + res;
        stk.pop_back();
    }
    return res;
}

string helper0(string s, int k){
    vector<pair<int,char>> stk{{0,'#'}};
    string res;
    for(char c:s){//遍歷陣列
        if(stk.back().second!=c){//"跟最後一個比較", 如果不相同, 就新增pair元素,推到stack
            stk.push_back({1,c});
        }else{//stk.back().second == c
            if(++stk.back().first==k){//"跟最後一個比較", 如果字元相等, stack的top內容做+1;
                stk.pop_back();//等於題目條件k, 就將stack中的資訊移除
            }
        }
    }
    for(auto a:stk){
        res.append(a.first,a.second);依據stack中的內容, 建立題目要的string
    }
    return res;
}

string removeDuplicates(string s, int k) {
    return helper0(s, k);
}

//===思路2===
(*)stack概念
1.以vector<pair<char,int>> 替代 stack
- pair<char,int> //character, count

2.stack的element
- count數目等於k, 則stack要pop_back()
while(!stk.empty() && stk.back().first==s[i]){
  if(stk.back().second==(k-1)) stk.pop_back();
}

-count數目小於k, 則stack push_back()
-- push_back({s[i],1});//如果s[i]不等於back()時
-- stk.back().second+=1;//如果s[i]等於back()時

3.最後依據stack中的element的內容建立string,即為解


string removeDuplicates(string s, int k){
    vector<pair<char, int>> stk;
    string res;
    
    for(int i=0; i<s.size(); ++i){
        int flag = 0;
        while(!stk.empty() && stk.back().first==s[i]){
            if(stk.back().second==(k-1)){
                stk.pop_back();
                flag = 1;
            }
            else break;
        }
        if(!flag){
            if(!stk.empty() && stk.back().first==s[i]) stk.back().second+=1;
            else stk.push_back({s[i],1});
        }
    }

    for(int i=0;i<stk.size();++i){
        res+=string(stk[i].second, stk[i].first);
    }
    return res;
}
//---同上思路, 只是String在過程中建立
(*)此方式會造成time limited exceeded
-因為 res = substr(0,res.size()-(k-1)); 會造成運算時間拉長

string helper2(string s, int k){
    vector<pair<char, int>> stk;
    string res;
    for(int i=0; i<s.size(); ++i){
        int flag = 0;
        while(!stk.empty() && stk.back().first==s[i]){
            if(stk.back().second==(k-1)){//need to pop
                stk.pop_back();
                res = res.substr(0,res.size()-(k-1));// time limited exceeded
                flag = 1;
            }
            else break;
        }
        if(!flag){
            if(!stk.empty() && stk.back().first==s[i]){ stk.back().second +=1;}
            else{ stk.push_back({s[i],1}); }
            res.push_back(s[i]);//time limited exceed
        }
    }
    return res;
}


