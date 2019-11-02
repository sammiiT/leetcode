class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int pre = -1;
        helper(root,res,pre);
        return res;
    }
    
  
    void helper(TreeNode *node, int& res, int& pre){
        if(!node) return;
        
        helper(node->left,res,pre);
        if(pre!=-1) res = min(res,abs(node->val-pre));
        pre = node->val;
        helper(node->right,res,pre);
        
    }
    
    

};