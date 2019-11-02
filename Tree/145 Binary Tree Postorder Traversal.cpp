class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    void helper(TreeNode* root, vector<int>& res){
        if(!root) return;
        
        helper(root->left,res);
        helper(root->right,res);
        res.push_back(root->val);
    }
};