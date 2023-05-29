(*)BFS(同一層窮舉所有可能)
(*)DFS(一直深入到最後一層)
(*)BFS 和 DFS同時互相使用

(*)pre-order trasversal
- BFS + DFS
void helper(TreeNode* root, vector<int>& res){
  if(!root) return;
  res.push_back(root->val);

//窮舉下一層所有可能, 下一層有left和right ; BFS
  helper(root->left,res);//每一次進入新的一層之後, 又馬上再進入下一層 ; DFS
  helper(root->right,res);
}
