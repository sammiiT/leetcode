//===類似題===
784. Letter Case Permutation
1254. Number of Closed Islands
2049. Count Nodes With the Highest Score
2445. Number of Nodes With Value One
//===思路===
(*) 解法與 "530 Minimum Absolute Difference in BST" 一樣
//=====
void helper(TreeNode* root, int& pre, int& res){
    if(!root) return;

    helper(root->left,pre,res);
    if(pre==-1) pre = root->val;
    else{ 
        res = min(res,abs(pre-root->val));
        pre = root->val;
    }
    helper(root->right,pre,res);
}

int minDiffInBST(TreeNode* root) {
        int pre = -1;
        int res = INT_MAX;
        helper(root,pre,res);
        return res;
}

//====
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int res =INT_MAX;
        int pre = -1;
        helper(root,pre,res);
        return res;
    }
    
    
    void helper(TreeNode* root, int& pre, int& res){
        if(!root) return;
        
        helper(root->left,pre,res);
        if(pre!=-1) res = min(res,abs(root->val-pre));
        pre = root->val;
        
        helper(root->right,pre,res);
        
    }
};
