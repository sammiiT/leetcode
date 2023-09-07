//===類似題===


//===思路===




//===思路===


//====

TreeNode* helper(TreeNode* root, vector<int>& res){
  if(!root->left && !root->right){
    res.push_back(root->val);
    return NULL;
  }
  if(root->left) root->left = helper(root->left,res); 
  if(root->right) root->right = helper(root->right,res);
  return root; 
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> ret;
    while(!root){
        vector<int> res;
        root = helper(root,res);
        ret.push_back(res);
    }
    return ret;
}
