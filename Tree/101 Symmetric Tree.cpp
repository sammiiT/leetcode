class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isSym(root->left,root->right);
    }
    
    bool isSym(TreeNode *left, TreeNode *right){
        if(left==NULL&&right==NULL) return true;
        if(!left&&right||left&&!right||left->val!=right->val)
            return false;
        return isSym(left->left,right->right)&&isSym(left->right,right->left);
    }
};