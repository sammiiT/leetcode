//===類似題===
1261. Find Elements in a Contaminated Binary Tree
1676. Lowest Common Ancestor of a Binary Tree IV
919. Complete Binary Tree Inserter

//===思路1===
pre-order概念
//====
void helper0(TreeNode* root, int& res){
    if(!root) return;
    if(!root->left && !root->right){
        res+=root->val;
        return;
    }
    helper0(root->left,res);
    helper0(root->right,res);
}
bool checkTree(TreeNode* root) {
  int res = 0;
  helper0(root,res);
  return (root->val==res);
}

//===思路2===
