//===more challenge ===

//===思路1===
(*)DFS

bool dfs(unordered_map<string,unordered_set<string>>& ump, string sstr, string tstr, unordered_map<string,int>& visited){
    if(sstr==tstr) return true;
    if(visited.count(sstr)) return false;
    
    visited[sstr]=1;
    for(unordered_set<string>::iterator it=ump[sstr].begin(); it!=ump[sstr].end(); ++it){
        if(dfs(ump,*it, tstr, visited)) return true;
    }
/*
    for(string str:ump[sstr]){
      if(dfs(ump,str,tstr,visited)) return true;
    }
*/ 
    return false;
}

bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    if(words1.size()!=words2.size()) return false;
    unordered_map<string,unordered_set<string>> ump;
    for(pair<string,string> p:pairs){
        ump[p.first].insert(p.second);
        ump[p.second].insert(p.first);
    }
    for(int i=0;i<words1.size();++i){
        unordered_map<string,int> visited;
        if(words1[i]==words2[i]) continue;
        if(dfs(ump,words1[i],words2[i],visited)==false) return false;
    }
    return true;
}

== DFS 寫法2 ===
bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>> m;
        for (auto pair : pairs) {
            m[pair.first].insert(pair.second);
            m[pair.second].insert(pair.first);
        }
        for (int i = 0; i < words1.size(); ++i) {
            unordered_set<string> visited;
            if (!helper(m, words1[i], words2[i], visited)) return false;
        }
        return true;
}
bool helper(unordered_map<string, unordered_set<string>>& m, string& cur, string& target, unordered_set<string>& visited) {
    if (cur == target) return true;
    visited.insert(cur);
    for (string word : m[cur]) {
        if (!visited.count(word) && helper(m, word, target, visited)) return true;
    }
    return false;
}


//===思路2===
(*)BFS
bool bfs(unordered_map<string,unordered_set<string>>& ump, string sstr, string tstr){
    queue<string> q;
    unordered_map<string,bool> visited;    
    q.push(sstr);
    visited[sstr]=1;
    while(!q.empty()){
        string p = q.front();q.pop();
        for(string s:ump[p]){
            if(visited[s]) continue;
            if(s==tstr) return true;
            visited[s]=1;
            q.push(s);
        }
    }
    return false;
}

bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    if(words1.size()!=words2.size()) return false;
    unordered_map<string,unordered_set<string>> ump;
    for(pair<string,string> p: pairs){
        ump[p.first].insert(p.second);
        ump[p.second].insert(p.first);
    }
    for(int i=0; i<words1.size(); ++i){
        if(words1[i]==words2[i]) continue;
        if(!bfs(ump,words1[i],words2[i])) return false;
    }    
    return true;
}

//===思路3===
(*)union find
(?) 建立個別群組之後, 最後如何縮減為單一群組???
=> 在判斷最後兩者不為同一root之後, 做合併, 則會變成同一群組

string getRoot(string word, unordered_map<string,string>& m){
    if(!m.count(word)) m[word]=word;
    return word==m[word]?word:getRoot(m[word],m);
}

bool areSentencesSimilarTwo(vector<string>& words1, 
                            vector<string>& words2, 
                            vector<pair<string, string>> pairs) {
    if(words1.size()!=words2.size()) return false;
    unordered_map<string,string> m;
    
    for(auto pair: pairs){//建立pairs[i]的group, 並接續判斷 接下來的pairs[i]是否也是在同一個group中
        string x = getRoot(pair.first,m), y = getRoot(pair.second,m);
        if(x!=y) m[x]=y;//不是同一個root, 則合併... // 此處定義 y為root (建立群組階段)
                        //第一個y是整個group的root
    }
    
    for(int i=0; i<words1.size(); ++i){//實際比較階段, 判斷words1[i]和words2[i]是否屬於同一個root
        if(getRoot(words1[i],m)!=getRoot(words2[i],m)) return false;
    }
    return true;
}



