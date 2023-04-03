//===類似題====
1718. Construct the Lexicographically Largest Valid Sequence
2135. Count Words Obtained After Adding a Letter

//===思路=====
(*)類似"())" balance的題目; 用資料結構stack和greedy概念解題
-因為有三個元素做比較, aba有"ab"的選擇 或 "ba"的選擇 

(*)先"正規化" max和 min的對應排列; 設定x對應的數值是最大的
string strmx = "ab";//x對應maximum
string strmi = "ba";//y對應minimum
if(y>x){
    int t = x;//
    x = y;
    y = t;
    strmx = "ba";
    strmi = "ab";
}

(*)
討論 bab 的選擇 ;可以選擇ba或ab, 依據得到的分數大小來選擇
- "ba" max => 剩下b
- "ab" max => 剩下a
ba max => ([i]==a)時, 判斷(stack.top==b) 
ab max => ([i]==b)時, 判斷(stack.top==a)

(*)遍歷2次數列, 第一次刪除maximum的subarray, 每一次刪除就累加得到的points
   第二次刪除minimum的subarray,每一次刪除就累加得到的points
--最後累加的points即為"解"

//=====
int helper0(string s, int x, int y){
    int res=0;
    string s1,s2;
    string strmx = "ab";//x
    string strmi = "ba";//y
    if(y>x){
        int t = x;
        x = y;
        y = t;
        strmx = "ba";
        strmi = "ab";
    }
    for(char c:s){
        int flag =0;
        while(!s1.empty()&& (s1.back()==strmx[0] && c==strmx[1])){
            res+=x;
            flag = 1;
            s1.pop_back();
            break;
        }
        if(!flag) s1.push_back(c);
    }
    for(char c:s1){
        int flag = 0;
        while(!s2.empty() && (s2.back()==strmi[0] && c==strmi[1])){
            res+=y;
            flag = 1;
            s2.pop_back();
            break;
        }
        if(!flag) s2.push_back(c);
    }
    return res;
}

int helper1(string s, int x, int y) {
    int res=0;
    string s1,s2;
    string strmx = "ab";//x
    string strmi = "ba";//y
    if(y>x){
        int t = x;
        x = y;
        y = t;
        strmx = "ba";
        strmi = "ab";
    }
    for(char c:s){
        if(s1.empty()|| !(s1.back()==strmx[0] && c==strmx[1]) ){
            s1.push_back(c);
        }else{
            res+=x;
            s1.pop_back();
        }
    }
    for(char c:s1){
        if(s2.empty()|| !(s2.back()==strmi[0] && c==strmi[1]) ){
            s2.push_back(c);
        }else{
            res+=y;
            s2.pop_back();
        }
    }
    return res;
}


int maximumGain(string s, int x, int y) {
    return helper1(s,x,y);
//    return helper0(s,x,y);        
}
