(*)BFS(Breadth-first search) 廣度優先搜尋; 
-是queue的概念
-窮舉同一層的所有可能來計算; 先計算同一層的所有節點, 再往下一層的所有節點做運算
-BFS(同一層窮舉所有可能)
--將同一層所有可能推到 queue中
--每一層的節點, 都先計算"成為解的可能性"才能推到queue中, 不然會造成time_limit_exceeded
--在push致下一個level之前, 先把判斷式做完, 確保push致queue的元素是正解

ex1: 棋盤                                            ex2: 二元樹
從A節點開始算起,                                      從A節點開始算起,                                      
BFS下一層,會算A節點的所有周邊節點D,B;                  BFS下一層,會算A節點的下層所有節點B,C;並記錄致queue
若算到D節點,會再紀錄D節點的所有周邊節點G,E              所以每一層的所有節點紀錄完, 都會是下一層的所有節點  
                                                     如B會推得D,E,並記錄到queue中; C會推得F,G,並記錄到queue中;所以下一層的BFS節點就是 D,E,F,G
                                                     
    +---+---+---+                                            A
    | A ->B | C |                                          /  \
    +-|-+---+---+                                        *B    *C
    | D | E | F |                                       /  \   / \
    +---+---+---+                                     +D   +E +F   +G 
    | G | H | I |                                     / \
    +---+---+---+                                   @H   @I


(*)與DFS(Depth-First-Search)深度優先搜尋不同概念
-DFS是stack的概念
-DFS是從一個節點開始, 會一直深入到最後一層, 每一次進入新的一層時, 可做計算;
--深入到最後一個節點計算完之後, 才會對最後一層的另外一個節點做運算

-DFS可以在同一個level做判斷, 或在下一個level做節點判斷; 
--因為DFS每一次指判斷一個節點, 不像BFS,會將所有不滿足的節點都push致queue中,導致計算量過大

ex1: 棋盤                           ex2: 二元樹 
從A節點開始找起,                     從A節點開始找起,
DFS會算D->G->H->I;                  DFS會算B->D->H;
每一個節點都是下一層,                每一個節點都是下一層,
直到最後一層I節點                    直到最後一層H節點                    
    +---+---+---+                         *A
    | A | B | C |                        /  \
    +-|-+---+---+                      *B    C
    | D | E | F |                     /  \   / \
    +-|-+---+---+                   *D   E  F   G 
    | G ->H ->I |                   / \
    +---+---+---+                 *H   I



(*)在binary tree的遍歷過程中; BFS和DFS概念同時存在; 如下
- pre-order trasversal(BFS + DFS)

void helper(TreeNode* root, vector<int>& res){
  if(!root) return;
  res.push_back(root->val);

//窮舉下一層所有可能, 下一層有left和right ; BFS
  helper(root->left,res);//每一次進入新的一層之後, 又馬上再進入下一層 ; DFS
  helper(root->right,res);
}
