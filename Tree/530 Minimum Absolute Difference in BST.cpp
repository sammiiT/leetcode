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

//===========================================
int minvalue(TreeNode *root){
        if(root->left){
            return minvalue(root->left);
        }else{
            return root->val;
        }
}
int maxvalue(TreeNode *root){
        if(root->right){
            return maxvalue(root->right);
        }else{
            return root->val;
        }
}
  //每一個parent都往比較最後一個right, left leaf.  
void helper(TreeNode* root, int& mni){
        if(!root) return;        
        int deltal = INT_MAX, deltar = INT_MAX;
  
        if(root->left) deltal = abs(root->val - maxvalue(root->left));//比較最後一個leaf
        if(root->right) deltar = abs(root->val- minvalue(root->right));//比較最後一個leaf
        
        mni = min(mni,deltal);
        mni = min(mni,deltar);
        
        helper(root->left,mni);//往下找下一個minimum
        helper(root->right,mni);//往下找下一個minimum
}
    
int getMinimumDifference(TreeNode* root) {
        int mni = INT_MAX;
        helper(root,mni);
        return mni;
}

