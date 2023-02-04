//===類似題====
146. LRU Cache
2477. Minimum Fuel Cost to Report to the Capital
//===思路====

//======
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    void helper(TreeNode* root, vector<int>& res){
        if(!root) return;
        
        helper(root->left,res);
        helper(root->right,res);
        res.push_back(root->val);
    }
};
