//===類似題===

//===思路===
(*)pre-order(DFS)
 1.初始化mi數值, 設定default為IN_MAX
 2.比較每一個節點與target的差異;如果比mi還要小,則記錄
 
//====思路1 ===
void helper(TreeNode* root, int& val, double& mi, double target){
    if(!root) return;
    if(abs((double)root->val - target) <= mi){
        mi = abs(root->val-target);
        val = root->val;
    }
    helper(root->left, val, mi, target);
    helper(root->right,val,mi, target);
}

int closestValue(TreeNode* root, double target){
    int val = root->val;
    double mi = INT_MAX;
    
    helper(root,val,mi,target);
    return val;
}

//===思路2===
(*)還是用pre-order思考
(*)只往接近target的節點運算

void helper(TreeNode* root, double target, int& diff, int& val){
  if(!root) return;
  int sub = abs(root->val - target);
  if(diff<sub) return;
  diff = sub;
  val = root->val;
  helper(root->left && target < root->val) helper(root->val,target,diff,val);
  helper(root->right && target > root->val) helper(root->val,target, diff,val);
}

 void helper(TreeNode* root, double target, int& diff, TreeNode** node){
   if(!root) return;
   int val = abs(root->val-taret);
   if(diff<val) return;
   diff=val;
   node =&root;
   if(root->left && target<root->val)  helper(root->left,target,diff,node);
   if(root->right && target>root->val) helper(root->right,target,diff,node);
 }
 int closestValue(TreeNode* root, double target){
   TreeNode* node = NULL;
   int diff = INT_MAX;
   helper(root,target,diff,&node);
   return node->val;
 }
//===思路3===

int closestValue(TreeNode* root, double target){
  int res = root->val;
  while(root){
      //舊節點的比較值     //新節點的比較值
    if(abs(res-target)>=abs(root->val-target)){
      res = root->val;  
    }
    root= (root->val < traget)?root->right:root->left;
  }
  return res;
 
}


