class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root,res);
        return res;
    }
    int diameterOfBinaryTree_OK(TreeNode* root) {
        int res = 0;
        int l=0,r=0;
        // if(!root) return 0;
        if(root && root->left) l=maxDepth(root->left,res);
        if(root && root->right) r=maxDepth(root->right,res);
        
        res = max(l+r,res);
        return res;
    }
    
    int maxDepth(TreeNode *root, int& res){
        if(root==NULL) return 0;
        int l=0,r=0;
        
        if(root->left) l = maxDepth(root->left,res);
        if(root->right) r= maxDepth(root->right,res);
        
        res = max(l+r, res);
        return 1 + max(l,r);
    }
    
    
    int maxDiameter(TreeNode *root, int& res){
        if(!root) return 0;
        
        int l=0,r=0;
        if(root->left) l = maxDiameter(root->left,res);
        if(root->right) r = maxDiameter(root->right,res);
        
        // res = max(res,1+l+r);不用此描述,因為是討論距離,不是個數
        res = max(res,l+r);
        return  1+max(l,r);
    }
    
    int helper(TreeNode* root,int& res){
        if(!root) return 0;
        int l = helper(root->left,res);
        int r = helper(root->right,res);
        
        res = max(res,l+r);
        return 1+max(l,r);
    }
};