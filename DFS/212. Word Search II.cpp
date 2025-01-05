//===類似題===
79. Word Search
980. Unique Paths III
2227. Encrypt and Decrypt Strings

//===思路====
(*)利用 Trie 字典樹, 並搭配 DFS 求解
(*)用Trie字典樹,可以正規畫計算, 一次計算多個條件(string)的可能
- 不用字典樹, 在原運算要多一個for loop,來依序判斷每一個string的存在

TrieNode中有一26元素的陣列, 每一元素, 都是一個TrieNode的指標, 
"同階層"且"同字母",會用到同樣的TrieNode節點
pitch
||      =====> 同階層,同字母; p i ;此兩字母會用到同一個TrieNode物件
pirate

    

//======
struct TrieNode{
    TrieNode(){
        isEndOfWord = false;
        child = vector<TrieNode*>(26,nullptr);
    }
    ~TrieNode(){
        for(TrieNode* n:child) if(n) delete n; 
    }
bool isEndOfWord;
vector<TrieNode*> child;    
};

struct Trie{
    Trie(){ root = new TrieNode();}
    void insert(string word){
        TrieNode* cur = root;
        for(char c:word){
            if(cur->child[c-'a']==nullptr) cur->child[c-'a']=new TrieNode();
            cur = cur->child[c-'a'];
        }
        cur->isEndOfWord = true;    
    }
    TrieNode* root;
};

void helper(vector<vector<char>>& board, 
            TrieNode* p, 
            string& out,
            int x, 
            int y, 
            vector<vector<bool>>& visited, 
            vector<string>& res,
            unordered_map<string,int>& mp){
    if((x<0)||(x>=board.size())||(y<0)||(y>=board[0].size())||(p==nullptr)||(visited[x][y])) return;

    out.push_back(board[x][y]);
    visited[x][y]=true;
    if(p->isEndOfWord) {
        if(!mp.count(out)){
            mp[out] = 1;
            res.push_back(out);
          //不做return是因為 "oa", "oaa"這種 element 存在於wordDict
        }
    }
//----- 下一層 ----
    if(x+1<board.size()){ //要先做x,y位置判斷, 因為參數board會牽扯到邊界問題
        helper(board, p->child[board[x+1][y]-'a'], out, x+1, y, visited, res,mp); }
    if(x-1>=0){            
        helper(board, p->child[board[x-1][y]-'a'], out, x-1, y, visited, res,mp); }
    if(y+1<board[0].size()){ 
        helper(board, p->child[board[x][y+1]-'a'], out, x, y+1, visited, res,mp); }
    if(y-1>=0){               
        helper(board, p->child[board[x][y-1]-'a'], out, x, y-1, visited, res,mp); }
//----- 下一層 -----

    visited[x][y]=false;
    out.pop_back();             
}



vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m = board.size(), n = board[0].size();
    vector<string> res;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    unordered_map<string,int> mp;
    Trie trie;
    TrieNode* p;
    string s;

    for(string str:words) trie.insert(str);//建立字典樹
    p = trie.root;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            helper(board,p->child[board[i][j]-'a'],s,i,j,visited,res,mp);        
        }
    }
    return res;
}
