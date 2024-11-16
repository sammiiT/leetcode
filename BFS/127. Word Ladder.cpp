//===類似題===
126. Word Ladder II
126. Word Ladder II
433. Minimum Genetic Mutation
2452. Words Within Two Edits of Dictionary
//===思路====
(*)BFS: Breath first search
1. 建立一個set來判斷是否有對應的key存在
unordered_set<string> wordSet(wordList.begin(),wordList.end());
wordSet中的key是 wordList中的每一個 string

2.建立一個unordered_map<string,int> , 紀錄每一次convert之後的累加次數
- 用unordered_map<string,int> 是紀錄每一個ladder出現的"歷史step數"
範例:
vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
歷史step_1:
hit->hot->dot->dog->cog
           | 
           +--- dot的歷史step數為3 => 以BFS, dot會先接到dog, queue中會先計算到dog,cog
                不會受到 "歷史step 2"和"歷史step_3"的影響, 即使dot被修改了, "歷史step_1"也不會受影響, 因為已經算到"dog"
歷史step_2:        
hit->hot->lot->dot->dog->cog
           |     \
           |      +--- dot的歷史step數為4
           +-- lot的歷史step數為3
        
歷史step_3:
hit->hot->dot->lot->log->cog
           |    |
           |    +--- lot的歷史step數4 
           +--- dot的歷史step數為3 
        
        
3.建立一個 queue<string> ,紀錄有出現在wordList中的string.

(*)BFS的邏輯出現在:
- 單字中的每一個letter變換"在同一層" 且範圍從"a~z"
- for(char c='a';c<='z';++c) {newtmp[i]=c;}

//======
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if(!wordSet.count(endWord)) return 0;
        unordered_map<string,int> mp{{beginWord,1}};

        queue<string> q{{beginWord}};
//        q.push(beginWord);

        while(!q.empty()){
            string tmp = q.front();q.pop();
 //           string newtmp = tmp;//incorrect
            for(int i=0; i<tmp.size(); ++i){
                string newtmp = tmp;
                for(char c='a';c<='z';++c){
                    newtmp[i]=c;
                    if(wordSet.count(newtmp) && newtmp==endWord) return mp[tmp]+1;
                    if(wordSet.count(newtmp) && !mp.count(newtmp)){
                        mp[newtmp]=mp[tmp]+1;
                        q.push(newtmp);
                    }
                }
            }
            
        }
        return 0;
}
//===寫法2====
int helper2(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(),wordList.end());
    unordered_map<string,int> visited;
    queue<string> q;
    int res = 0;

    if(!wordSet.count(endWord)) return 0;
    q.push(beginWord);
    visited[beginWord]=1;
    while(!q.empty()){
        ++res;
        for(int i=q.size(); i>0; --i){
            string p=q.front();q.pop();
            
            for(int j=0; j<p.size(); ++j){
                string t = p;
                
                for(char c='a'; c<='z'; ++c){
                    t[j]=c;
                    if(wordSet.count(t) && t==endWord) return res+1;
                    if(wordSet.count(t) && !visited.count(t)) {
                        q.push(t);
                        visited[t]=1;
                    }
                }//for c<='z'
            }//for p.size()
        }//for q.size()
    }//while(!q.empty())
    return 0;
}

//===寫法3=====
(*)BFS
(*)wordLadder特性一定是, 每次可以變一個字母, 變一個字母之後的單詞,會存在於wordList中

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    set<string> wordset(wordList.begin(),wordList.end());
    unordered_map<string,int> visited;//用來計算ladder次數,也可用來判斷是否訪問過
    queue<string> q;
    
    q.push(beginWord);
    visited[beginWord] = 1;//
    
    while(!q.empty()){
        string p = q.front();q.pop();
        
        for(int i=p.size(); i>=0; --i){
            string str = p;
            
            for(char c='a'; c<='z'; ++c){
                str[i] = c;
                if(wordset.count(str) && str ==endWord) return visited[p]+1;
                if(wordset.count(str) && visited.count(str)) continue;//訪問過,用continue, 有可能會出現 hog,hot,hoe,同樣第[2]個出現不同字母
                if(wordset.count(str)){
                    visited[str] = visited[p]+1;//記錄新出現的string所經過的步數
                    q.push(str);
                }
            }
        }
    }
    return 0;
}
//===寫法4===
(*)比寫法2慢
-寫法2在運算過程中若滿足題目定義, 則馬上回傳 (res+1)
for(char c='a'; c<='z'; ++c){
   t[j]=c;
   if(wordSet.count(t) && t==endWord) return res+1;           

-寫法4 是在解 queue<string>的過程當中, 才去判斷, 會多一到deque的過程


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string,bool> visited;
    queue<string> q;
    int res = 0;
    set<string> st;
    for(string str:wordList) st.insert(str);

    if(st.count(endWord)==0) return 0;
    
    q.push(beginWord);
    visited[beginWord]=1;

    while(!q.empty()){
        res++;
        for(int i=q.size(); i>0; --i){
            string p = q.front();q.pop();
            if(p==endWord) return (res);
            
            string tmp;
            for(int j=0; j<p.size();++j){
                for(int k=0;k<26;++k){
                    tmp = p;
                    tmp[j] = 'a'+ k;
                    if(visited[tmp] || !st.count(tmp)) continue;
                    q.push(tmp);
                    visited[tmp]=1;
                }
            }    
        }
    }  
    return 0;      
}
