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

//=====
用inorder方式, 輸出的順序會不一樣; 
preorder方式才能滿足題目要求
void helper(TreeNode *root, string s, vector<string>& res){
        if(!root) return;
        
        helper(root->left,s+"->",res);
        s = s+to_string(root->val);
        res.push_back(s);
        
        helper(root->right,s+"->",res);
}
