//===類似題===

//===思路====
(*)DFS

pattern = abab
string =  xxxyyyxxx
            
if(!mp.count(c)){
    bool b = false;
    for(auto it:mp){
        if(it.second==tmp) b = true;            
    }
}

(*)此題的考點是 , 如何找出 對應的pattern (列出對應的pattern) => unordered_map<char, string>
(*) 下一層 i = start的節點, 可當作是一個root節點
for(i=start;i<str.size();++i) => start ~ (str.size()-1) 都是一個 substring.

            
(*)此種算法的執行流程會是: 示意圖
a b c          p==pattern.size() 當其中一個遇到 index = size()時; 要退回前一個 index(不管是p或者是r)              
 \ \ \ 
  x x x y y y    

a b c          p==pattern.size()     
 \ \ \
  x x xy y y

a b c          p==pattern.size()
 \ \ \ 
  x x xyy y

a b c         p==pattern.size()  兩個同時達到end index; 則pattern可以與string對應
 \ \ \ 
  x x xyyy    r==str.size()      兩個同時達到end index; 則pattern可以與string對應


(*)以此種算法,可推論其發生false的情況為; 其中一個string先到達對應的size()
p==pattern.size() || r==str.size()

(*)
-此種算法, "遇到false時,會退到上一層, 再上一層從新作排列配對", 
-重新配對的substring,往下一層計算, 判斷是否會滿足pattern match => 在同一層的重新配對, 是由for loop中的 i~j範圍作重新配對
-對應的pattern(重新配對的pattern) 發生true(配對成功), 則再往下一層繼續配對
-若退到最上層(且(i~j)遍歷到最後一個),都發生false, 則沒有pattern match發生

//=====
bool helper(string& pattern, 
            int p, 
            string& str, 
            int r, 
            unordered_map<char,string>& mp){
    if(p==pattern.size() && r==str.size()) return true;
    if(p==pattern.size() || r==str.size()) return false;


    char c = pattern[p];
    for(int i=r; i<str.size(); ++i){// string全部遍歷完
        string tmp = str.substr(r,i-r+1);
        if(mp.count(c) && mp[c]==tmp){
            if(helper(pattern,p+1,str,i+1,mp)) return true;
        
        }else if(!mp.count(c)){//for迴圈同一層計算還沒計算到匹配的,有可能i~某個j 會匹配,則走上一個描述
            bool b = fasle;
            for(auto it:mp){
                if(it.second==tmp) b=true;//有存在才不會重複計算, 且將之前map對應的value覆蓋
            }
            if(!b){//!mp.count(c) 且 tmp不存在
                mp[c]=tmp;
                if(helper(pattern,p+1,str,i+1,mp)) return true;
                mp.erase(c);
            }
        }
    }
    return false;
}

bool wordPatternMatch(string pattern, string str){
    unordered_map<char,string> mp;
    return helper(pattern,0,str,0,mp);
}
