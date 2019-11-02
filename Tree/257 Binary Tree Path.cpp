class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root,{},res);
        return res;
    }
    
    void helper(TreeNode *root, string s, vector<string>& res){
        if(!root) return;
        
        s=s+to_string(root->val);
        if(!root->left && !root->right){
            res.push_back(s);
        }
        else{
            helper(root->left,s+"->",res);
            helper(root->right,s+"->",res);
        }
    }
};