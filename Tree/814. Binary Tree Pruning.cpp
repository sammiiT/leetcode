//===類似題====
815. Bus Routes
1586. Binary Search Tree Iterator II
968. Binary Tree Cameras
1644. Lowest Common Ancestor of a Binary Tree II

//===思路====
(*) tree post-order算法
1. post-order遍歷tree, 最後一個node的性質
node->left==NULL; node->right==NULL;

2.如果在最後一個節點的值等於0, 則此節點刪除
如果節點的right或left有一個不為NULL, 就算節點值等於零, 不會被刪除

3.post-order遍歷的最後回傳值(最上層回傳值), 即為解

//=====
TreeNode* helper(TreeNode* root){
    if(!root) return NULL;

    root->left = helper(root->left); 
    root->right= helper(root->right);

    if(!root->left && !root->right && root->val==0) return NULL;
    return root;

}

TreeNode* pruneTree(TreeNode* root) {
  return helper(root);
}
