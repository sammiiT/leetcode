//===類似題==
1490. Clone N-ary Tree
1485. Clone Binary Tree With Random Pointer
1490. Clone N-ary Tree

//===思路===
(*)BFS+DFS
-BFS部分, 是for(Node* n:node->neighbors)
-DFS部分, 是 每次進入clone->neighbors.push_back(helper(n,mp)),並不會將同一層for loop執行完; 而是一直進入下一層
   A-------B                 
   |       |
   |       |
   Y-------X
  
-建立新節點的順序, A-->B-->X--->Y--->'A'
-A已經在map中,且有對應的clone, 所以直接回傳給Y
-接著Y那一層, 會接著計算剩下相鄰的node(除了A之外的節點);對應的節點是X
-X也已經在map中建立,有對應的clone, 所以會直接回傳給Y
-Y的BFS計算完成,跳回上一層X;計算X剩下的(BFS)相鄰節點
-接下來的節點以此類推

(*)用map紀錄 clone值,每一個舊的NODE都會對應一個新的NODE

//====
Node* helper(Node* node, unordered_map<Node*,Node*>& mp){
  if(!node) return NULL;
  if(mp.count(node)) return mp[node]; 
  
  Node* clone = new Node(node->val);
  mp[node]=clone;
  for(Node* n:node->neighbors){
    clone->neighbors.push_back(helper(n,mp));
  }
  return clone;
}

Node* cloneGraph(Node* node) {
   if(!node) return NULL;
   unordered_map<Node*,Node*> mp;
   queue<Node*> q;
   q.push(node);

   Node* clone = new Node(node->val);
   m[node] = clone;
    while(!q.empty()){
       Node* t = q.front();q.pop();
       for(Node* neighbor:t->neighbors){
          if(!mp.count(neighbor)){
             Node* clone = new Node(neighbor->val);
             mp[neighbor]=clone;
             q.push(neighbor);
          }
          m[t]->neighbors.push_back(m[neighbor]);
       }
    }
   return clone;
}
