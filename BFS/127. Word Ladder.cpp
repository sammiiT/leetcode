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
