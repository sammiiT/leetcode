//===類似題===
152. Maximum Product Subarray
186. Reverse Words in a String II

//===思路====

//====
string helper0(string s){
        vector<string> res;
        string t;

        for(int i=0;i<=s.size();i++){
//            if(s[i]==' '||i==s.size()){//如果遇到space或i等於s.size();超過index 
             if(i==s.size()||s[i]==' '){//要先判斷i==s.size(), 因為超出範圍s[i]==' '的s[i]不存在            
                if(t.size()){          //將紀錄的string記錄至vector<string>中
                    res.push_back(t);
                    t.clear();        
                }
            }else{
                t+=s[i];
            }        
        }
        t.clear();
        for(int i=res.size()-1; i>=0; --i){//reserve
            t+=res[i];
            if(i>0) t+=' ';            
        }
        return t;
}

string helper1(string s){
        string r;
        string t;
        for(int i=0; i<=s.size(); i++){
//            if(s[i]==' '|| i==s.size()){
            if(i==s.size()||s[i]==' '){//要先判斷i==s.size(), 因為超出範圍s[i]==' '的s[i]不存在  
                if(t.size()){
                    (r.size()==0)?r.insert(0,t):r.insert(0,t+' ');        
                    t.clear();
                }        
            }else{ t+=s[i]; }
        }
        return r;
}

string reverseWords(string s) {
        return helper0(s);
}
