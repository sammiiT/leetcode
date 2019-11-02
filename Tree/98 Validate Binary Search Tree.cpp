class Solution {
public:
    bool isValidBST(TreeNode *root){
        if(!root) return true;
        if(root->left && root->val<=MaxValue(root->left)) return false;
        if(root->right && root->val>=MinValue(root->right)) return false;
        return isValidBST(root->left)&&isValidBST(root->right);
    }
    bool isValidBST_OK(TreeNode* root) {
        if(root==NULL) return true;
        
        if(root->left && root->val<=maxValue(root->left))
            return false;
        
        if(root->right && root->val>=minValue(root->right))    
            return false;
        
        return isValidBST(root->left) && isValidBST(root->right);    
    }
    
    int minValue(TreeNode *root){
        if(root->left) return minValue(root->left);
        else return root->val;
    }
    
    int maxValue(TreeNode *root){
        if(root->right) return maxValue(root->right);
        else return root->val;
    }
    
    
    int MinValue(TreeNode *root){
        while(true){
            if(root->left) root= root->left;
            else return root->val;
        }
    }
    int MaxValue(TreeNode *root){
        while(true){
            if(root->right) root=root->right;
            else return root->val;
        }
    }
};