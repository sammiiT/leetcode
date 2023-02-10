//===類似題===
701. Insert into a Binary Search Tree
270. Closest Binary Search Tree Value
2476. Closest Nodes Queries in a Binary Search Tree
//===思路===
(*)pre-order運算 DFS
-從上往下找的概念
-如果遇到target節點,則回傳到上層(做截斷用;找到就不繼續往下找)
-如果沒遇到target,就繼續往下找
-回傳到上層的節點,也要比較;分別有left和right, 如果存在,就回傳存在的節點(可能是left或right)
-- return left?left:right;

(*)post-order (DFS)
- 從下往上找地概念
- 如果遇到節點等於target,則回傳當下節點給上層
-如果沒有遇到target,最後會回傳NULL給上層
- 回傳給上層的節點分別有left和right,要做比較,如果存在TreeNode*,則繼續往上回傳


  
(*)用binary search tree的特性,
-如果小於target就往right找
-如果大於target就往left找
-如果等於, 就回傳當下節點
-因為利用binary_tree,所以不會找其他的路徑,所以不會有遇到一邊NULL,一邊TreeNode*
  
//====

TreeNode* helper0(TreeNode* root, int val) {
    if(!root) return NULL;
  
    if(root->val==val) return root;

    TreeNode* l = searchBST(root->left,val);
    TreeNode* r = searchBST(root->right,val);
    return l?l:r;        
}

TreeNode* helper1(TreeNode* root, int val) {
    if(!root) return NULL;

    TreeNode* l = helper1(root->left,val);
    TreeNode* r = helper1(root->right,val);
    
    if(root->val==val){ return root; }
    return l?l:r;
//    return NULL;//不能用此,因為要考慮上一層的l和r
}

TreeNode* helper2(TreeNode* root, int val){
    if(!root) return NULL;
    
    if(root->val < val){
        TreeNode* t = helper2(root->right,val);
        return t;
    }else if(root->val > val){
        TreeNode* t = helper2(root->left,val);
        return t;
    }
    //()root->val == val)
    return root;
}

TreeNode* searchBST(TreeNode* root, int val) {
        return helper2(root,val);
        //return helper1(root,val);
    }
