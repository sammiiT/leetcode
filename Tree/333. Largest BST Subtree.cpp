//===類似題===

//===思路====
(*)利用validate binary search tree的解法概念
(*)inorder解法
1.用inorder判斷是不是validate BST,多加1個參數count,此count是用來計算node個數
2.遍歷每一個節點,並將每一個遍歷的節點作為root,往下遍歷
3.遍歷過程中計算節點的數目(count)
4.如果判斷是BST,則將count跟mx做比較
5.遍歷完所有的node,則回傳mx  
  
//======

int helper(TreeNode* root, long& pre, int& count){
  if(!root) return true;
 
  int l = helper(root->left, pre);
  if(pre>=root->val) return false;//只有回傳此層, 上一層的上一層並沒有回傳這一層false,所以要在座後加上判斷描述
  pre = root->val;
  count++;
  int r = helper(root->right,pre);
  return (l&&r)?true:false;//一直回傳到上層
}

int largestBSTSubtree(TreeNode* root){
  int mx = 0;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
      TreeNode* n = q.front(); q.pop();
      if(n->left) q.push(n->left);
      if(n->right) q.push(n->right);
      
      long pre = LONG_MIN;
      int count = 0;
      if(helper(n,pre,count)){
          mx = max(mx,count);
      }
  }
  return mx;
}



//====TBD====
/*
void helper(TreeNode* root, long& pre, int& res , int& count){
  if(!root) return;
  helper()
  if(pre>=root->val) res = false;  
  pre = root->val;
  
  helper()  
  
}*/
