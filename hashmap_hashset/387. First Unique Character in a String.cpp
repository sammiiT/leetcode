//===類似題===
388. Longest Absolute File Path
2351. First Letter to Appear Twice
//===思路====

//====
int helper1(string s) {
    int letters[26]={0};
    for(char c:s) letters[c-'a']++;
    for(int i=0; i<s.size(); i++){
        if(letters[s[i]-'a']==1) return i;
    }
    return -1;
}
    int helper0(string s) {
        unordered_map<char,int> mp;//char, count
        for(char c:s){
            mp[c]++;
        }

        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1) return i;
        }
        return -1;
    }

    int firstUniqChar(string s) {
        return helper1(s);
    //    return helper0(s);
    }
