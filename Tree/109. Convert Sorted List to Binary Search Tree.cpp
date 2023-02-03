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
  
   node->left = sortedListToBST(head);
   node->right =sortedListToBST(f->next);
   
  return node; 
}
