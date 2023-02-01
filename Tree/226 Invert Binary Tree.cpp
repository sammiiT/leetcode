//===類似題===
227. Basic Calculator II
2415. Reverse Odd Levels of Binary Tree
//===思路===
(*) post_ordder trasversal
-遍歷到最後一個節點,將最後一個節點的left和right相互對調, 對調後再將此parent回傳給上一層


    O                O            O -->回傳給上一層
   / \        =>    / \    =>    / \   
  L   R            R   L        R   L
  
     
   
      X  ----->對於X, O和*要對調        X
     / \                              / \ 
    O    *                           *   O
   / \  / \                         / \ / \
  R   L R  L                       R  L R  L 
//====
class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root){
        if(!root) return NULL;
        TreeNode *l=NULL,*r=NULL;
        if(root->left)  l = invertTree(root->left);
        if(root->right) r = invertTree(root->right);
        
//        執行步驟在父節點
        root->right = l;//parent節點運算
        root->left = r;//parent節點運算
        return root;
    }
    
    TreeNode* invertTree_OK2(TreeNode* root){
        if(!root) return NULL;
        if(root->left) root->left = invertTree(root->left);
        if(root->right)root->right= invertTree(root->right);
        
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
    
    TreeNode* invertTree_OK(TreeNode* root) {
        if(root==NULL) return NULL;
    
        invertTree(root->left);
        invertTree(root->right);
    
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        
        return root;    
    }
};




//===== 錯誤寫法; 原因 =====
void helper(TreeNode** left, TreeNode** right){
    if(!(*left)&&!(*right)) return;
    TreeNode *tmp = *left;//->left指向的位址
    *left = *right; //root->left
    *right = tmp;
    helper(&((*left)->left),&((*left)->right));//由上往下找,會有null pointer出現, 錯誤
    helper(&((*right)->left),&((*right)->right));    
/*
preorder寫法會造成中間有null pointer形成, 要避免
(*)用postoer或 inorder概念, 可以避免null pointer.
(*)要知道前一個node(父node); 可以用postoer或indorer, 因為執行步驟在父節點
*/

}

//===== 錯誤寫法; 原因 =====
void helper(TreeNode** left, TreeNode** right){
    if(!(*left)&&!(*right)) return;
        
    TreeNode *tmp = *left;//->left指向的位址
    *left = *right; //root->left
    *right = tmp;
        
    helper(&((*left)->left),&((*right)->right));
    helper(&((*left)->right),&((*right)->left));    
}
TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    helper(&root->left,&root->right);
    return root;
}
原因:
初始:
4
2 7
1 3 6 9

第一次執行:
4
7 2    
6 9 1 3
    
第二次執行:
4
7 2
3 1 9 6   => 答案錯誤












