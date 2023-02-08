//===類似題===
939. Minimum Area Rectangle
1568. Minimum Number of Days to Disconnect Island
993. Cousins in Binary Tree
1257. Smallest Common Region
//===思路===
(*)pre-order (DFS)
 1.如果節點值 "大於等於" low, "小於等於" high
 -將其累加
//====

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        int res = 0;
        helper(root,L,R, res);
        return res;
    }
    
    
    void helper(TreeNode* root, int L, int R, int& res){
        if(!root) return;
        
        if(root->val >=L && root->val<=R){
            res+=root->val;
        }
        
        helper(root->left,L,R,res);
        helper(root->right,L,R,res);
    }
};
