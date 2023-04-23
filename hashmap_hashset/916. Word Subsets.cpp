//===類似題====
1982. Find Array Given Subset Sums
889. Construct Binary Tree from Preorder and Postorder Traversal
502. IPO
1086. High Five

//===思路====
(*) 

(*)建立unordered_map<char,int>紀錄words2每一個string中的character的個數,並取出相同character中的最大值
- words2=["eel","llo","ap"]
<e,2>,<l,2>,<o,1>,<a,1>,<p,1>

(*) 如果words1每一個string的element有在map中出現
且 element的個數 >= map中的個數, 則words2[i]是words1[i]subset的subset

//=====
unordered_map<char,int> char_cnt(string& s){
    unordered_map<char,int> mp;
    for(char c:s){ mp[c]++; }
    return mp;
} 
vector<string> helper1(vector<string>& words1, vector<string>& words2) {
    unordered_map<char,int> mp;
    vector<string> res;

    for(string s:words2){
        unordered_map<char,int> tmp = char_cnt(s);
        for(auto a: tmp){
            if(mp.count(a.first)){
                mp[a.first] = max(mp[a.first],a.second);
            }else{
                mp[a.first]=a.second; }
        }
    }

    for(string s:words1){
        unordered_map<char,int> tmp = char_cnt(s);
        unordered_map<char,int>::iterator it;
        for(it=mp.begin(); it!=mp.end(); ++it){
            if(tmp.count(it->first) && tmp[it->first]>=it->second) continue;//words1[i]的某個character個數一定要大於等於subset中character的個數
            break;
        }
        if(it==mp.end()) res.push_back(s);
    }
    return res;
} 
//===思路2===
(*)用陣列來做, 會比map作要快
//=======
vector<int> count(string& s){
    vector<int> ret(26,0);
    for(char c:s) ret[c-'a']++;
    return ret;
}

vector<string> helper2(vector<string>& words1, vector<string>& words2) {
    vector<int> mp(26,0);
    vector<string> res;

    for(string s:words2){
        vector<int> tmp = count(s);
        for(int i=0;i<26;++i)
            mp[i] = max(mp[i],tmp[i]);
    }
    for(string s:words1){
        vector<int> tmp = count(s);
        int i=0;
        for(i=0;i<26;++i){
            if(tmp[i]>=mp[i]) continue;
            break;
        }
        if(i==26) res.push_back(s);
    }
    return res;
}

//===
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
          return helper2(words1,words2);  
 //       return helper1(words1,words2);
    }
