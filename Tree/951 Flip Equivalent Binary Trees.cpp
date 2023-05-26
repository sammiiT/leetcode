//===類似題===
952. Largest Component Size by Common Factor
2246. Longest Path With Different Adjacent Characters
1644. Lowest Common Ancestor of a Binary Tree II
2322. Minimum Score After Removals on a Tree
//===思路===
(*)flip equivalent
-兩個binary tree完全相等 => 其中一個tree的任何subtree做 flip 2 次之後, 會等於另外一個binary tree
-兩個binary tree不相等, 但其中一個tree的一個subtree做flip 1次,還是可以等於另外一個binary tree


(*)可以當作isSymmetric的擴展
-除了最後判斷 (flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left)) 之外
還要做一個 "||"的判斷, 判斷同樣方向的兩節點是否相等,left_child比left_child, right_child比right_child
(flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right))
    
(*)DFS概念, 窮舉所有路徑可能 
- 路徑1:判斷是否為symmetric => (flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right))
- 路徑2:同一層節點,經過flip之後是否為symmetric => (flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left))
//=====
class Solution{
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        
        if(!root1&&root2 || root1&&!root2 || root1->val!= root2->val) return false;
        
        return (flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left))
            ||(flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right));

        //中間可以不對調,或可對調, 所以要加上(root1->left,root2->left),(root1->right,root2->right)
        // logic operator運算順序 && , ||
    }
};
