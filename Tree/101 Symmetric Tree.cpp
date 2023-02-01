//===類似題===
102. Binary Tree Level Order Traversal
1254. Number of Closed Islands
1236. Web Crawler
1197. Minimum Knight Moves
//===思路===
(*)算法有點像pre-order
(*)先將兩個節點的做比較,
-如果兩個不相等,則直接回傳false,這樣就不會繼續往下一個節點找=>斷點
-不相等的情形包括: 一個節點存在,一個節點不存在; 兩個節點都存在,但數值不相等

(*)如果能比較到最後一個節點,且兩節點都是NULL, 則回傳true
//====
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isSym(root->left,root->right);
    }
    
    bool isSym(TreeNode *left, TreeNode *right){
        if(left==NULL&&right==NULL) return true;
        if(!left&&right||left&&!right||left->val!=right->val)//preorder概念
            return false;
        return isSym(left->left,right->right)&&isSym(left->right,right->left);
    }
};
