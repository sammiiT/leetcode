class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q) return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right= lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        return left?left:right;//往上連結, return往上連結
    }
    
};
//如果只有left, 回傳left
//如果只有right, 回傳right
//有兩個left, right, 回傳當下的root