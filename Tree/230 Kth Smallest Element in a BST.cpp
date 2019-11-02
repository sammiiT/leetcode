class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int c=k;
        int count=0;
        
        // helper_2(root,k, count,res);
        helper(root,k,res);
        return res;
        
        
    }
    
    void helper(TreeNode* root, int& k, int& res){
        if(!root) return;
        
        helper(root->left,k,res);
        k--;
        if(k==0){
            res = root->val;
            return;
        }
        helper(root->right,k,res);
    }
    
    void helper_(TreeNode *node, int k, int& count, int& res){
        if(node==NULL) return;
        
        helper_(node->left, k, count, res);
        count+=1;
        if(count==k){
            res = node->val;
            return;
        }
        helper_(node->right, k, count,res);
    }
};