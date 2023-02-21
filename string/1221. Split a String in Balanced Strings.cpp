//===類似題===
1222. Queens That Can Attack the King
828. Count Unique Characters of All Substrings of a Given String
1663. Smallest String With A Given Numeric Value
2000. Reverse Prefix of Word
//====思路===
1.遍歷數列1次
2.遇到R, count+=1; 遇到L, count-=1
3.如果count==0,則代表substring可以split
//===
int helper1(string s){
    int res = 0;
    int count = 0;
    for(char a:s){
        if(a=='R') count+=1;
        else count-=1;
        if(count==0) res+=1;
    }
    return res;
}

//===思路2===
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
