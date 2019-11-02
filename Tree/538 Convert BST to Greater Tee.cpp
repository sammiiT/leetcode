class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root,sum);
        return root;
    }
    
    void helper_OK(TreeNode *root,int &sum){
        if(!root) return;
        if(root->right) helper(root->right,sum);
        root->val += sum;
        sum = root->val;     
        if(root->left) helper(root->left,sum);
    }
    
    void helper_OK2(TreeNode *root, int& sum){
        if(!root) return;
        
        helper(root->right,sum);
        
        if(sum!=0) root->val = root->val +sum;
        // root->val = root->val +sum;
        sum = root->val;
        
        helper(root->left,sum);
    }
    
    void helper(TreeNode* root, int& res){
        if(!root) return;
        helper(root->right,res);
        if(res!=0) root->val = root->val+res;
        res = root->val;//加完之後給下一個
        helper(root->left,res);
    }
    
};