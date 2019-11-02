class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int res =INT_MAX;
        int pre = -1;
        helper(root,pre,res);
        return res;
    }
    
    
    void helper(TreeNode* root, int& pre, int& res){
        if(!root) return;
        
        helper(root->left,pre,res);
        if(pre!=-1) res = min(res,abs(root->val-pre));
        pre = root->val;
        
        helper(root->right,pre,res);
        
    }
};