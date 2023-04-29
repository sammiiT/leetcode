//===類似題===

//===思路====
(*)DFS


//=====
bool helper(string& pattern, 
            int p, 
            string& str, 
            int r, 
            unordered_map<char,string>& mp){
    if(p==pattern.size() && r==str.size()) return true;
    if(p==pattern.size() || r==str.size()) return false;


    char c = pattern[p];
    for(int i=r; i<str.size(); ++i){
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
