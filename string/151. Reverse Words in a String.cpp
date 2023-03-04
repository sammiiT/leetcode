//===類似題===
152. Maximum Product Subarray
186. Reverse Words in a String II

//===思路====
1.如果做in-lplace運算,會比較複雜,因為
space出現的位置可能在字串首,也可能在字串尾,而且中間有連續出現space的可能

2.所以把每一個單詞從字串中挑選出來,做reverse之後,再加上' '重新組合.

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
//====思路2====
string helper2(string s){
    vector<string> res;
    string t;
    for(int i=0;i<=s.size();i++){
        if(i==s.size()||s[i]==' '){
            if(t.size()){
                res.push_back(t);//將每一個單詞重新取出,加到vector陣列
                t.clear();
            }
        }else{
            t+=s[i];
        }
    }
    t.clear();
    reverse(res.begin(),res.end());//將單詞做reverse
    for(int i=0; i<res.size(); i++){//重新組合,加上space
        t+=res[i];
        t+=' ';//加上space
    }
    return t.substr(0,t.size()-1);//取出substring, 將最後一個space去掉       
}
//===思路3===
(*)string運算
str.insert(str.begin(),'A');//插入character
str.insert(str.begin(),"hello");//不能插入一個string, 會有錯誤
str.insert(0,"hello");//插入一個string
str.erase(str.begin()+(str.size()-1));//移除最後一個character

(*)利用 istringstream來計算

string helper3(string s){
    istringstream in(s);
    string res;
    string val;
    for(;in>>val;){
        res.insert(0,val+" ");
    }
    res.erase(res.begin()+(res.size()-1));
    return res;
}
