class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root){
        
        int diff = maxDepth(root->left)-maxDepth(root->right);
        return (diff==0)? root: subtreeWithAllDeepest(diff>0?root->left:root->right);
    }
    
    TreeNode* subtreeWithAllDeepest_ok(TreeNode* root) {
        int diff = maxDepth(root->left) - maxDepth(root->right);
        
        if(diff==0) return root;//
        else if(diff>0){
            return subtreeWithAllDeepest(root->left);//左邊比較深
            
        }else{//diff<0
            return subtreeWithAllDeepest(root->right);//右邊比較深
        }
    }
    int maxDepth(TreeNode* root){
        return (!root)? 0: max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    
    int maxDepth_ok(TreeNode* root){
        if(!root) return 0;
        
        int l=0,r=0;
        if(root->left) l = maxDepth(root->left);
        if(root->right)r = maxDepth(root->right);
        
        return 1+max(l,r);
    }
};