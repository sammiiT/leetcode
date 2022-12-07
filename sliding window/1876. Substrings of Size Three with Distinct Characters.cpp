    bool threeDistinct(string s){
        vector<int> l(26,0);
        for(int i=0;i<s.size();i++){
            if(l[s[i]-'a']) return false;
            else l[s[i]-'a']++;
        }
        return true;
    }

    int countGoodSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i=3,j=0; i<=n; i++,j++){
            if(threeDistinct(s.substr(j,i-j))) res++;     
        }
        return res;
    }
