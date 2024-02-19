//===類似題===
1485. Clone Binary Tree With Random Pointer
133. Clone Graph
1485. Clone Binary Tree With Random Pointer
1490. Clone N-ary Tree

//===思路===
(*)deep copy概念:
變數拷貝,數值一樣,但位址不一樣
(*)遍歷舊的, 順便建立新的
1.先建立新的鏈結
2.建立random的map
3.再依據random map建立新連結的random

//=======
Node* copyRandomList(Node* head) {
  if(!head) return head;
  unordered_map<Node*,Node*> mp;
  Node *res,*cur,*nd;
    
  res = new Node(head->val,NULL,NULL);
  cur = head->next;
  mp[head]=res;
  nd = res;
  while(cur){
      Node* t = new Node(cur->val,NULL,NULL);
      mp[cur]=t;
      nd->next=t;
      nd = nd->next;
      cur = cur->next;
  }
  nd = res; cur = head;
  while(cur){
      nd->random = mp[cur->random];
      nd = nd->next;
      cur = cur->next;
  }
  return res;
}

//====思路2===
(*)DFS算法
  
1.先新節點建立; 方向 --->                              
        nxt1  nxt2  nxt3  nxt4
        O ->  O ->  O ->  O -> X
        rnd4  rnd3  rnd2  rnd1
        
2.再建立random節點; 方向 <---                     

Node* helper(Node* node, unordered_map<Node*, Node*>& m){
    if(!node) return NULL;
    if(m.count(node)) return m[node];
    
    Node* n = new Node(node->val,NULL,NULL);
    m[node]=n;
    n->next = helper(node->next,m);//DFS會先遍歷完 linked-list
    n->random = helper(node->random,m);//遍歷到最後一個, list的random才會開始計算
                                     //因為random還沒開始計算, 所以(!node)不會成立, 而是(m.count(node))會成立
    return n;                        //計算完random就回往上傳, 不會node->next做DFS; 所以不會重複計算
}

//===思路3====
(*)DFS算法令解 : 比較好理解
1.先連結node節點 
2.再連結random節點
Node* helper(Node* head, map<Node*,Node*>& mp){
    if(!head) return head;
    Node* n = new Node(head->val);
    mp[head] = n;
    n->next = helper(head->next,mp);
    return n;
}

Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        Node* node = NULL;
        node = helper(head,mp);//先連結node本體

        for(auto a:mp){//再連結random節點
            //a.first//old_node
            //a.second//new_node
            if(a.first->random==NULL){
                a.second->random=NULL;
            }else{//a.first->random!=NULL
                a.second->random=mp[a.first->random];
            }
        }
        return node;    
}
