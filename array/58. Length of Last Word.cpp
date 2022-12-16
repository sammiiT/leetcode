//===類似題====
59. Spiral Matrix II
556. Next Greater Element III
824. Goat Latin
953. Verifying an Alien Dictionary
//====思路===

//=====
int helper0(string s){
        int res = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==' '&& res==0) continue;
            if(s[i]==' ') break;
            res++;
        }
        return res;
}
int lengthOfLastWord(string s) {
        return helper0(s);
}
