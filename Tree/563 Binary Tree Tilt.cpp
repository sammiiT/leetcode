class Solution {
public:
    int findTilt(TreeNode* root) {
        int res = 0;
        postOrder(root,res);
        return res;
    }
    
    int postOrder(TreeNode *root, int& res){
        if(!root) return 0;
        
        int l=0,r=0;
        if(root->left) l = postOrder(root->left,res);
        if(root->right) r = postOrder(root->right,res);
        
        res = res+abs(l-r);
        return l+r+root->val;
    }
    
};