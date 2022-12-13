//====類似題======
15. 3Sum
1410. HTML Entity Parser
1702. Maximum Binary String After Change
1750. Minimum Length of String After Deleting Similar Ends

string lcp(string s1,string s2){
        string res;    
        int n=min(s1.size(),s2.size());
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) res+=s1[i];
            else break;
        }
        return res;
}
string helper1(vector<string>& strs){
        string res;
        res = strs[0];
        for(int i=1; i<strs.size(); i++){
            res = lcp(strs[i],res);//兩兩比較,找出相同的prefix
        }
        return res;
}    

string longestCommonPrefix(vector<string>& strs) {
        return helper1(strs);
}

//========fail============
    string helper0(vector<string>& strs){
        int mi=201;
        int letter;
        string res;

        for(int i=0; i<strs.size(); i++){
            mi = min((int)strs[i].size(), mi);        
        }

        for(int i=0;i<mi;i++){    
            int count = 0;
            letter = strs[0][i];
            for(int j=0;j<strs.size();j++){
                count+=strs[j][i];
            }
            if(letter*strs.size() == count){//錯誤, 第一個char分別是 b,a,b,c=>出錯
                res+=letter;                
            }else break;
        }
        return res;
    }
