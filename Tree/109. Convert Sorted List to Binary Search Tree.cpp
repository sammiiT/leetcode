//===類似題=====
110. Balanced Binary Tree
2196. Create Binary Tree From Descriptions

//===思路====
(*)同Convert Sorted Array to Binary Search Tree
-用post-order + pre-order
-每次都找second-middle
(*)每次都要找second-middle, second-middle的前一個節點,second-middle的後一節點
(*)如果遞迴帶入
-沒有節點:回傳NULL
-只有一個節點:建立一個TreeNode節點,回傳
//=====
TreeNode* sortedListToBST(ListNode* head) {
//if(!head||!head->next) return NULL;//會出錯
  if(!head) return NULL;//沒有節點,就回傳NULL
  if(!head->next) return new TreeNode(head->val);//只有一個節點, 回傳TreeNode
  
  ListNode *f,*r,*t;
  f=r=head;
  while(r&&r->next){
    t=f;
    f=f->next;
    r=r->next->next;
  }
  
  TreeNode* node = new TreeNode(f->val);
  t->next=NULL;
  
   node->left = sortedListToBST(head);//要跟下面的節點做連接
   node->right =sortedListToBST(f->next);
   
  return node; 
}
//====思路2===
(*)用post order做運算
(*) height balance要取second_middle的前一個作為left part, 
right part就是 second_middle後的節點開始算起

TreeNode* helper2(ListNode* head) {
    if(!head||!head->next){
        return !head?NULL:new TreeNode(head->val);
    }
    ListNode *f,*b;
    ListNode *c;
    f = b = head;
    while(b&&b->next){
        c = f;
        f=f->next;
        b=b->next->next;
    }
    ListNode* t = f->next;
    c->next = NULL;
    
    TreeNode* l = sortedListToBST(head);
    TreeNode* r = sortedListToBST(t);
    
    TreeNode* n = new TreeNode(f->val);
    n->left = l; //跟下一層的節點做連接
    n->right = r;
    return n;
}
