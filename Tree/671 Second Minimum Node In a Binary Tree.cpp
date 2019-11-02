class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        long first = root->val, second = LONG_MAX;
        helper(root, first, second);
        // return (second == first || second == LONG_MAX) ? -1 : second;
        return (second==LONG_MAX)?-1:second;
    }
    
    void helper(TreeNode* node, long &first, long &second){
        if (!node) return;
    
        //用此運算是條件:數列是sort的狀態之下, Tree必須用pre-order方式
        //不是sort也可以用此運算
        if (node->val != first && node->val < second) {
            second = node->val;
        }
        helper(node->left, first, second);
        helper(node->right, first, second);
    }

    
};