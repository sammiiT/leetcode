//===類似題===
1124. Longest Well-Performing Interval
1676. Lowest Common Ancestor of a Binary Tree IV
//===思路====

(*)smallest subtree with deepest node
- 如果有兩個以上的deepest node, 則要找到其common ancestor
- 如果只有一個deepsett node, 只要回傳此deepest node; 

(*)利用maxDepth
-判斷左右path的maxDepth是否相等, 如果相等,則回傳此level的root節點
-如果不相等, 就往下一個節點做運算, 下一個節點的選取, 選擇dpeth最長的的那一個節點
-只有一個deepest node, 則最後的判斷會 node->left==NULL, node->right==NULL, if(diff==0) return root;//此root是deepest node
//===
int  maxDepth(TreeNode* root){
    if(!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l,r)+1;
}
 TreeNode* helper(TreeNode* root){
    int diff = maxDepth(root->left)-maxDepth(root->right);//判斷maxDepth是否相同
    if(diff==0) return root;//相同則回傳此root
    return helper(diff>0?root->left:root->right);//不相同的maxDepth, 取比較常的那一個繼續運算
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    reutrn helper(root);
}
