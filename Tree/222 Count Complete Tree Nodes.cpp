class Solution {
public:
    int countNodes_(TreeNode* root) {
        if(root==NULL) return 0;
        
        int count = 0;
        count+=countNodes(root->left);
        count+=countNodes(root->right);
        
        return 1+count;
        
    }
    
    int countNodes(TreeNode *root){
        if(!root) return 0;
        
        int l=0,r=0;
        if(root->left) l = countNodes(root->left);
        if(root->right) r= countNodes(root->right);
        
        return 1+r+l;
    }
};