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
