//===類似題===
708. Insert into a Sorted Circular Linked List
687. Longest Univalue Path
250. Count Univalue Subtrees
255. Verify Preorder Sequence in Binary Search Tree

//===思路===
(*)利用inorder概念, 將數值填入tree的leaf
-利用BST性質, 其路徑就是單一路徑,不會有其他結果存在

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val <=val){
            if(root->right) root->right=insertIntoBST(root->right,val);
            else root->right=new TreeNode(val);
        }else{//root->val >val
            if(root->left) root->left=insertIntoBST(root->left,val);
            else root->left = new TreeNode(val);
        }
        return root;
    }
};

//====
TreeNode* helper(TreeNode* root, int val){
    if(!root) return NULL;        
    if(val<root->val) {
        if(root->left) root->left = helper(root->left,val);
        else root->left = new TreeNode(val);
    }   
    if(val>root->val) {
        if(root->right) root->right = helper(root->right,val);
        else root->right = new TreeNode(val);
    }
    return root;
}    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return root?helper(root,val):new TreeNode(val);
    }
