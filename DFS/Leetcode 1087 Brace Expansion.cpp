//===思路===

void dfs(string& s, int i, string in, vector<string>& res){
    if(i==s.size()){
        res.push_back(in);
        return;
    }
    //不用 for(int i=start;i<s.size();++i)的方式, 達到遍歷所有節點的方式
    if(s[i]=='{'){
        string tmp="";
        vector<string> str;
        
        while(s[i]!='}'){
            if(s[i]>='a' && s[i]<='z'){
                tmp+=s[i];
            }else {
                if(tmp.size()>0) str.push_back(tmp);
                tmp="";
            }
            ++i;
        }
        //
        str.push_back(tmp);
        for(int j=0; j<str.size(); ++j){
            dfs(s,i+1,in+str[j],res);
        }
    }else{//
        dfs(s, i+1, in+s[i],res);
    }
}

vector<string> brace_expansion(string s){
    vector<string> res;
    dfs(s,0,"",res);
    return res;
}
