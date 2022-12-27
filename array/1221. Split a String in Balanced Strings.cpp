//===類似題===
1222. Queens That Can Attack the King
828. Count Unique Characters of All Substrings of a Given String
1663. Smallest String With A Given Numeric Value
2000. Reverse Prefix of Word

//====思路===

//===
int helper0(string s){
    string l;
    string r;
    int res = 0;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='R') r+=s[i];
        else// s[i]=='L'
            l+=s[i];
        
        if(r.size()==l.size()){
            ++res;
            l.clear();
            r.clear();
        }
    }
    return res;
}

int balancedStringSplit(string s) {
    return helper0(s);       
}
