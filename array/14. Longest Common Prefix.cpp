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
