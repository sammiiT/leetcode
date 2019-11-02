class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         
        if(!root) return NULL;
        
        if(root->val <=val){
            if(root->right) root->right=insertIntoBST(root->right,val);
            else root->right=new TreeNode(val);
        }else{//root->val >val
            if(root->left) root->left=insertIntoBST(root->left,val);
            else root->left = new TreeNode(val);
        }
        return root;
    }
    
    
};