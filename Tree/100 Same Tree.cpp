//===類似題===
101. Symmetric Tree
2368. Reachable Nodes With Restrictions
301. Remove Invalid Parentheses
959. Regions Cut By Slashes

//===思路===
(*)有點像pre-order概念
1.在當下的節點就判斷是否相等,
-如果相等,就繼續往下一層找, 最後一層是兩個節點都是NULL, 如果兩個節點都是NULL則回傳true
-如果不相等, 就回傳false,從當下那一層截斷, 不往下層找
    
//=====
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        
        if(!p&&q || p&&!q || p->val!=q->val) return false;
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};
