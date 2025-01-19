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

//====寫法2 ====
(*)先建立每一個舊結點對應的新節點
(*)遍歷每一個舊節點,舊節點的 neighbor節點,會對應到前一個動作所建立的新節點,將其新節點作為neighbor加入

Node* cloneGraph(Node* node) {
    unordered_map<Node*,Node*> mp;
    queue<Node*> q;
    if(!node) return NULL;
    q.push(node);
    mp[node] = new Node(node->val);

    while(!q.empty()){//動作1
        Node* n = q.front();q.pop();
        for(Node* it:n->neighbors){
            if(mp.count(it)) continue;
            q.push(it);
            mp[it] = new Node(it->val);
        }
    }
   
    for(auto it:mp){//動作2
        for(Node* neighbor:it.first->neighbors){
            it.second->neighbors.push_back(mp[neighbor]);
        }
    }
    return mp[node];
}
//=== 寫法2 優化 ====
Node* bfs(Node* node, unordered_map<Node*,Node*>& ump){
    if(!node) return node;
    queue<Node*> q;
    q.push(node);
    ump[node] = new Node(node->val);

    while(!q.empty()){
        Node* ond = q.front(); q.pop();//old node
        for(Node* n: ond->neighbors){
            if(ump.count(n)) {//如果沒有此項 會發生 [2,4][3][][] ; 新節點沒辦法完整連結
                ump[ond]->neighbors.push_back(ump[n]);
            } else {
                ump[n] = new Node(n->val);
                ump[ond]->neighbors.push_back(ump[n]);
                q.push(n);
            }
        }
    } 
    return ump[node];
}


//====錯誤寫法====
Node* cloneGraph(Node* node){
    unordered_map<Node*,Node*> mp_c;//<old,clone>
    queue<Node*> q;
    
    if(!node) return NULL;
    
    q.push(node);
    
    while(!q.empty()){
        Node* n = q.front();q.pop();
        Node* clone = new Node(n->val);//此描述要放在for
        mp[n]=clone;//此描述要放在for
        
        for(Node* it: n->neighbors){
            if(mp.count(it)) continue;
            q.push(it);
        }
    }
}
(*)上面的描述會造成重複push

 (1)--------(2)
  |          |
  |          |
 (4)--------(3) 


1節點會造成; push(4),push(2)進queue
當執行到4時 執行for(neighbor), 會push(3); 1已經在map中
接著執行2 執行for(neighbor), 還是會push(3); 但3已經在前一個描述被push一次了===> 會造成錯誤, 也會造成time_limited_exceeded

