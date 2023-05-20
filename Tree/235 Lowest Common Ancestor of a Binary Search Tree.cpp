//===類似題===
236. Lowest Common Ancestor of a Binary Tree
1257. Smallest Common Region
1644. Lowest Common Ancestor of a Binary Tree II
1650. Lowest Common Ancestor of a Binary Tree III

//===思路===

isSymetric , isValid 概念一樣:中途遇到就回傳, 做截斷,不會往下繼續

找到節點之後, 回傳節點給上一層(做截斷)

回傳到某一層, 左邊回傳節點 和 右邊回傳節點 都存在 
=> (l&&r), 左右回傳節點就是傳入的p,q 
=> 回傳當下的節點就是lowest parent節點

當沒有(l&&r),則回傳左節點或右節點;此時有兩種情況
0.當沒有找到時,l?l:r 都是回傳NULL.
1. 左右節點都是NULL, 會一直回傳到上層, 直到某一層有找到p或q,就變成回傳p或q
   此時是找到但一一個節點
2. 當遇到(l&&r)回傳parent_node,此時在上層的每一層變成判斷l?l:r


(*)如何解釋當lowest anscetor等於p或q的情況???
如果此狀況發生, 則return的描述永遠只會執行return l?l:r;//只會有一個滿足題意, 由post-order遍歷,只會找到一個節點   
若p和q不在同一個lowest ancestor上, if(l&&r) return root; 會被執行到一次;會找到兩個節點p和q   
//===
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q) return root;//截斷下一層, 不往下一層執行
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);
        
        if(left && right) return root;//回傳上一層, 此層結果傳給上一層; 下一層結果傳給上一層 
        return left?left:right;
        
    }
};
