class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root){
        if(!root) return NULL;
        TreeNode *l=NULL,*r=NULL;
        if(root->left)  l = invertTree(root->left);
        if(root->right) r = invertTree(root->right);
        
        root->right = l;
        root->left = r;
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