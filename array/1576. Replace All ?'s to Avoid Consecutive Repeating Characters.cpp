//===類似題===
1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers
434. Number of Segments in a String
411. Minimum Unique Word Abbreviation
1119. Remove Vowels from a String
//===思路====
1.判斷條件, 有4種,此4種分別有相關 => 區分成三個區間
(i==0 || s[i-1]!=c) && (i==s.size()-1 || s[i+1]!=c)

i==0 ,s[i+1]!=c  =>第一個區間
s[i-1]!=c, i==s.size()-1 =>第二種區間
s[i-1]!=c,s[i+1]!=c =>第三種區間
每一種區間要做的事情都一樣  
//=====

string helper0(string s){

    for(int i=0; i<s.size(); i++){
        if(s[i]!='?') continue;
        for(char c:"abc"){//s[i]=='?'
            if((i==0 || s[i-1]!=c) && (i==s.size()-1 || s[i+1]!=c)){//列出所有判斷可能和邊界條件
                s[i]=c;
                break;
            }    
        }
    }
    return s;
}

string modifyString(string s) {
  return helper0(s);    
}
