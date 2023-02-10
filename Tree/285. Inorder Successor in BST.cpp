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
//這樣傳遞參數是錯誤的, 因為pre和suc是上層指標的副本,所以回到上層時,pre和suc的指標內容是不會改變的
//必須用global變數來取代local的pre和suc
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
=>>>>>>>>>>>>>修正>>>>>>>>>>>>>>>>>>>
TreeNode* pre=NULL; TreeNode* suc=NULL;
void helper(TreeNode* root, TreeNode* p){
  if(!root) return NULL;
  helper(root->left,p);
  if(pre==p) suc=root;
  pre=root;
  helper(root->right,p);
}
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
  helper(root,p);
  return suc?suc:NULL;
}


