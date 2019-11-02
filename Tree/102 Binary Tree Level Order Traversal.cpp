class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,0,res);
        
        return res;
    }
    
    void helper(TreeNode* root, int level, vector<vector<int>>& res){
        if(root==NULL) return;
        if(res.size()==level) res.push_back({});
        res[level].push_back(root->val);
        
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
        
    }
};