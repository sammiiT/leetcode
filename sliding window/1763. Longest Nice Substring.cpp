    bool isNice(string s){//判斷大小寫是否成對
        vector<int> u(26),l(26);//大寫26個, 小寫26個
        for(int i=0;i<s.size();i++){
            if(isupper(s[i])){//
                u[s[i]-'A']=1;        
            }else{
                l[s[i]-'a']=1;    
            }        
        }
        return (l==u);//vector互相比較
    }
    string helper0(string s){
        int n = s.size();
        string res="";
        for(int i=1;i<=n;i++){
            for(int j=0; j<i; j++){
                string tmp = s.substr(j,i-j);
                if(isNice(tmp) && tmp.size()>res.size()){ ret = tmp; }
            }
        }
        
    }
    
    string helper(string s){
        int n = s.size();
        string res="";
        for(int i=1; i<=n; i++){//窮舉所有的string
            for(int j=0; j<i; j++){
                string tmp = s.substr(j,i-j);
                if(isNice(tmp)){
                    if(tmp.size()>res.size()){
                        res = tmp;
                    }
                }
            }
        }        
        return res;
    }

    string longestNiceSubstring(string s) {
        return helper(s);
    }
