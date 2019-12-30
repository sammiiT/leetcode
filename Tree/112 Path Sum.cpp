class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        
        if(!root->left && !root->right){
            sum = sum -root->val;
            if(sum==0)return true;
            else return false;
        }else{
			//root->left==NULL || root->right!=NULL
			//root->left!=NULL || root->right==NULL
			//root->left!=NULL || root->right!=NULL
            return hasPathSum(root->left,sum-root->val)||
                hasPathSum(root->right,sum-root->val);
        }
    }
    // void helper(TreeNode* root, int sum, vector<int>& out)
};