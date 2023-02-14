//===類似題====
59. Spiral Matrix II
556. Next Greater Element III
824. Goat Latin
953. Verifying an Alien Dictionary
//====思路1===
(*)從最後一個元素開始算起
if(s[i]==' '&& res==0) continue; //是防止最後的空格
if(s[i]==' ') break;//倒數第一個string之後的
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
//===思路2===
(*)使用istringstream來運算
//=====
int helper1(string s){
  istringsteam in(s);
  string word;
  while(in){
    in>>word;
  }
  return word.size();
}
