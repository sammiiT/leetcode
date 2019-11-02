class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,0,res);
        return res;
    }
    
    void helper(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root) return;
        
        if(level==res.size()) res.push_back({});
        if(level%2){
            res[level].insert(res[level].begin(),root->val);
        }else{
            res[level].push_back(root->val);
        }
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
    }
};