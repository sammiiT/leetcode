class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res = {};
        int level = 0;
        helper(root,level,res);
        
        reverse(res.begin(),res.end());
        return res;
        // return vector<vector<int>>(res.rbegin(),res.rend());
    }
    
    void helper(TreeNode* root, int level, vector<vector<int>> &res){
        if(root==NULL) return;
        
        if(res.size()==level) res.push_back({});
        
        res[level].push_back(root->val);
        level+=1;
        helper(root->left,level,res);
        helper(root->right,level,res);
    }
};