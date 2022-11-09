class Solution {
public:
    //post order
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        int l=0,r=0;
        
        if(root->left) l = maxDepth(root->left);
        if(root->right) r = maxDepth(root->right);
        
        return 1 + max(l,r);
    }
    
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }
};
