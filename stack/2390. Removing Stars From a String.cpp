//===類似題===
2391. Minimum Amount of Time to Collect Garbage
844. Backspace String Compare
//===思路===
(*)用stack資料結構, 遍歷數列
0.用vector<char>來模擬stack行為
1.如果遇到字元a~z;將字元push至stack
2.遇到'*', 刪除stack.top;stack.pop; 且不做push
3.最後的stack數列即為解

//======

string helper0(string s) {
    string stk;
    for(char c:s){
        int rmflag = 0;
        while(!stk.empty() && c=='*'){
            rmflag=1;
            stk.pop_back();
            break;
        }
        if(!rmflag && c!='*') stk.push_back(c); 
    }        
    return stk;
}
//===思路2===

string helper1(string s){
    string res;
    for(char c:s){
        if(res.size() && c=='*') res.pop_back();
        else res.push_back(c);
    }
    return res;
}

string removeStars(string s) {
    return helper1(s);
//    return helper0(s);
}
