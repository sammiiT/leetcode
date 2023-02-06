//===類似題===
564. Find the Closest Palindrome
1469. Find All The Lonely Nodes
//===思路===
(*)post-order算法
//====
int helper(TreeNode* root, int& sum){
    if(!root) return 0;
    int l = helper(root->left,sum);
    int r = helper(root->right,sum);
    sum += abs(l-r);
    return root->val +l +r;
}
    int findTilt(TreeNode* root) {
        int sum = 0;
        helper(root,sum);
        return sum;
    }
//====
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
