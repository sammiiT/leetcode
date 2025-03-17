===


#=====
(*)dfs


  vector<string> dfs(string& s, int& i){
    vector<string> ret;
    string str;
    if(i==s.size()) return ret;
    while(i<s.size()){
        if(s[i]=='{'){
            vector<string> tmp = dfs(s,++i);            
            for(int i=0; i<tmp.size(); ++i) tmp[i]=str+tmp[i];
            if(ret.size()==0) {
                ret = tmp;
            } else {
                vector<string> cur = ret;
                ret.clear();
                for(int i=0; i<cur.size(); ++i) {
                    for(int j=0; j<tmp.size(); ++j){
                        ret.push_back(cur[i]+tmp[j]);
                    }
                }
            }
            str.clear();
        }else if(s[i]=='}'){
            ret.push_back(str);
            str.clear();
            return ret;
        }else if(s[i]==','){
            ret.push_back(str);
            str.clear();
        }else{//s[i]==character
            str=str+s[i];
        }
        ++i;
    }
    if(ret.size()==0) ret.push_back(str);
    else
        for(int i=0;i<ret.size();++i) ret[i] = ret[i]+str;
    return ret;
}

string expand(string s) {
    vector<string> ret;
    string res;
    int index = 0;
    ret = dfs(s,index);
    for(int i=0;i<ret.size();++i){
        res = res + ret[i]+',';
    }
    res.pop_back();
    return res;//res.pop_back();
}

