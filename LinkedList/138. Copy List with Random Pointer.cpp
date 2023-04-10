//===類似題===
1485. Clone Binary Tree With Random Pointer
133. Clone Graph
1485. Clone Binary Tree With Random Pointer
1490. Clone N-ary Tree

//===思路===
(*)deep copy概念:
變數拷貝,數值一樣,但位址不一樣

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
