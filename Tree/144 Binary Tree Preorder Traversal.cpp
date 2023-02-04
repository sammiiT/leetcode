//===類似題===
145. Binary Tree Postorder Traversal
255. Verify Preorder Sequence in Binary Search Tree
//===思路====

//======
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    void helper(TreeNode* root,vector<int>& res){
        if(!root) return;
        
        res.push_back(root->val);
        helper(root->left,res);
        helper(root->right,res);
            
    }
};
