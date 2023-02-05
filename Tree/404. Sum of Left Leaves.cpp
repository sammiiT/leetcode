//===類似題===
405. Convert a Number to Hexadecimal
106. Construct Binary Tree from Inorder and Postorder Traversal
2385. Amount of Time for Binary Tree to Be Infected
200. Number of Islands
//===思路===
(*)pre-order (DFS)
1.每次進入,計算有沒有存在left節點
-如果有left節點,則判斷此left節點是否有left和right節點;如果都沒有,就滿足題目條件,加入sum

//=====
void helper(TreeNode* root, int& res){
    if(!root) return;
    if(root->left && (!root->left->left && !root->left->right)){
        res+=root->left->val;
//        return;//有這一行會發生錯誤,因為還有root->right沒有判斷到
    }
    helper(root->left,res);
    helper(root->right,res);
}
int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        helper(root,res);
        return res;
}
