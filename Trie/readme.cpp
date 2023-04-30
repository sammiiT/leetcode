字典樹:
1.每一個節點都是一個string中的某個character
2.root節點紀錄每一個string的起始character
3.節點定義一個26個字母的vector<TrieNode*>
-每一個TrieNode* 都依序代表一個string中存在的character


        root
         |
+--------+-----------------+
||||..26 pointer.|||||||||||
  |              |         | 
  \n1            \n2        \n3
+--+--+        +--+--+     +-+-------+ 
||...||        ||...||     || 26 ptr | 
                            | 
                             \n4        
                            +-+---+ 
                            ||...||
                             |
                             \n5
                            +-+---+  
                            ||||  |
ex:
class Trie{
public:
struct TrieNode{
    TrieNode(){
        isEndOfWord = false;
        children = vector<TrieNode*>(26,nullptr);
    }
    ~TrieNode(){
      for(auto child: children) 
        if(child) delete child;
    }
bool isEndOfWord;
vector<TrieNode*> children;
};  
  
  Trie(){
    root = new TrieNode();
  }
  
  
  void insert(string word){
    TrieNode* curr = root;
    for(char ch:word){
        if(curr->children[ch-'a']==nullptr){
            curr->children[ch-'a'] = new TrieNode();
        }
        curr = curr->children[ch-'a'];
    }
    curr->isEndOfWord = true;
  }
  
  
  bool search(string word){
    TrieNode* curr = root;
    for(char c:word){
        if(curr->children[c-'a']==nullptr) return false;
        curr= curr->children[c-'a'];
    }
    return curr->isEndOfWord;
  }
  
  
  bool startWith(string prefix){
     TrieNode *curr = root;
      for(char c:prefix){
          if(curr->children[c-'a']==nullptr) return false;
          curr = curr->children[c-'a'];
      }
      return true;
  }
  
private:
  TrieNode* root;
}
//===========用 map 來表示 ==========



