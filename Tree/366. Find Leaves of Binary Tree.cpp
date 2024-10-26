//===類似題===


//===思路===




//===思路===


//====
(*)pre-order transversal
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
//===思路2===
(*) post-order transversal
  TreeNode* helper(TreeNode* root, vector<int>& leafs){
    if(root==NULL) return NULL;
    TreeNode* l, *r;
    
    l = helper(root->left,leafs);
    r = helper(root->right,leafs);
    
    if(!l && !r) {
        leafs.push_back(root->val);
        return NULL;
    }
    return root;
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    while(root!=NULL){
        vector<int> l;
        helper(root,l);
        res.push_back(l);
    }    
    return res;
}
