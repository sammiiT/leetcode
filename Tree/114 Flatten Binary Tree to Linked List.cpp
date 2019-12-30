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


