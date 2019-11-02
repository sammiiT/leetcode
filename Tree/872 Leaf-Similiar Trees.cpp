class Solution {
public:
   bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1,leaf2;
        helper(root1,leaf1);
        helper(root2,leaf2);
        return leaf1==leaf2;
    }
    
    void helper(TreeNode *n, vector<int> &res){
        if(!n) return;
/*
[3,5,1,6,2,9,8,null,null,7,4]
[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
*/        
         if(!n->left && !n->right){//左節點,右節點同時為NULL,則記錄此節點
            res.push_back(n->val);
         }
        
        helper(n->left,res);
        helper(n->right,res);
    }
};