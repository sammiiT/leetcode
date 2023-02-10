//===類似題===
(*)求解inoder遍歷的時 target節點的下一節點

//===思路===

//====
void helper(TreeNode* root, TreeNode* p, vector<TreeNode*>& res){
    if(!root) return;
    helper(root->left, p, res);
    if(root==p|| (res.size()==1)){ 
        res.push_back(root); 
    }
    helper(root->right,p,res);
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    vector<TreeNode*> res;
    helper(root,p,res);
    return (res.size()==2)? res.back():NULL;
} 

//===思路2==

//======
void helper(TreeNode* root, TreeNode* p, TreeNode* pre, TreeNode* suc){
  if(!root) return NULL;
  helper(root->left,p,pre,suc);
  if(pre==p) suc=root;
  pre=root;
  helper(root->right,p,pre,suc);
}
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
  TreeNode *pre=NULL,*suc=NULL;
  helper(root,p,pre,suc);
  return suc?suc:NULL;
}
