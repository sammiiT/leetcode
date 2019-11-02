class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        int res = 0;
        helper(root,L,R, res);
        return res;
    }
    
    
    void helper(TreeNode* root, int L, int R, int& res){
        if(!root) return;
        
        if(root->val >=L && root->val<=R){
            res+=root->val;
        }
        
        helper(root->left,L,R,res);
        helper(root->right,L,R,res);
    }
};