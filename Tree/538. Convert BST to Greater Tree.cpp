//===類似題===
539. Minimum Time Difference
1430. Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
1810. Minimum Path Cost in a Hidden Grid
1740. Find Distance in a Binary Tree

//===思路====
(*)inorder (DFS)
 1. inorder解法,但要先遍歷right, 再left
 2. 每次紀錄節點的累加,並將累加數值指派給當下節點
 3. 遍歷完, 即是解
//=======
void inorder(TreeNode* root, int& sum){
        if(!root) return;
        inorder(root->left, sum);
        sum = sum + root->val;
        root->val = sum;
        inorder(root->right, sum);
 }
    
void revInorder(TreeNode* root, int& sum){
        if(!root) return;
        revInorder(root->right,sum);
        sum = sum+root->val;
        root->val = sum;
        revInorder(root->left,sum);
}
    
    //inorder的反方向
TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        revInorder(root,sum);
        return root;
}
