//===類似題===
95. Unique Binary Search Trees II
173. Binary Search Tree Iterator
272. Closest Binary Search Tree Value II
285. Inorder Successor in BST
//===思路===

//=======
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    
    void helper(TreeNode *node, vector<int>& res){
        if(node==NULL) return;
    
        helper(node->left,res);
        res.push_back(node->val);
        helper(node->right,res);
    }
};
