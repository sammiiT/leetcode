class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *res = NULL;
        helper(root,val,&res);
        return res;
    }
    TreeNode* searchBST_OK(TreeNode* root, int val) {
        if(!root) return NULL;
        
        if(root->val<val){
            return searchBST(root->right,val);    
        }else if(root->val>val){
            return searchBST(root->left,val);
        }else{
            return root;
        }
    }
    
    void helper(TreeNode *root, int val, TreeNode** res){
        if(!root) return;
        
        if(root->val < val){
            helper(root->right,val,res);
        }else if(root->val > val){
            helper(root->left,val,res);
        }else{
            *res = root;
        }
     
    }
    
};