class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        
        
    int res = min(minDepth(root->left),minDepth(root->right));
        return 1+ res;
    }
};