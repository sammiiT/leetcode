class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        if(root->val > R) return trimBST(root->left,L,R);
        if(root->val < L) return trimBST(root->right,L,R);
        
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
        return root;
    }
    
    TreeNode* trimBST_OK(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        
        //binary search tree才可以用此方法
        if(root->val > R) return trimBST(root->left, L,R);
        
        //binary search tree才可以用此方法
        if(root->val < L) return trimBST(root->right, L, R);
            
        root->left = trimBST(root->left, L, R);
        root->right= trimBST(root->right, L, R);
        
        return root;
    }
};