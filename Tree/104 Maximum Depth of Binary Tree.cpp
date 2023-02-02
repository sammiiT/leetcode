//===類似題===
105. Construct Binary Tree from Preorder and Inorder Traversal
1376. Time Needed to Inform All Employees
2385. Amount of Time for Binary Tree to Be Infected
2458. Height of Binary Tree After Subtree Removal Queries
//===思路===
(*)post-order解法  (DFS)
-每一層節點,都會接收到下一層的left和right的最長長度
-得到left和right之後, 在當下那一層比較left和right長度,回傳比較長的那一個給上層
-回傳較長的那一個給上層,同時還要加1, 代表當下層的節點數

(*)第一次走到最深的節點,只會回傳1給上層,因為left和right都是NULL,所以只會有一個節點往上層傳


//==========
class Solution {
public:
    //post order
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        int l=0,r=0;
        
        if(root->left) l = maxDepth(root->left);
        if(root->right) r = maxDepth(root->right);
        
        return 1 + max(l,r);
    }
    
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }
};
