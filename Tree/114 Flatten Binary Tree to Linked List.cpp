class Solution {
public:
	//post-order概念
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);
        
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        while(root->right) root = root->right;
        root->right = tmp;
        
    }
};

      1
     / \
    2   5
   / \   \
  3   4   6

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

//----錯誤; 原因----
    void helper(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right) return;
//        if(!root->left && root->right) return;//此描述錯誤
         if(root->left) helper(root->left);
        if(root->right) helper(root->right);
        
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        while(root->right){
            root = root->right;
        }
        root->right = tmp;
    }

if(!root->left && root->right) return; 如果right底下還有child,其底下的child不會做運算(swap).








