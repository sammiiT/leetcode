//===類似題===
//===思路 BFS====
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
//===思路 DFS inorder====
//(1)計算subtree是否滿足BST,且節點記數
int countNode(TreeNode* root,//每一層的節點
              int& pre,     //前一個node數值, 用來判斷是否滿足BST
              int& count)   //subtree的個數
  if(!root) return true;
  if(!countNode(root->left,pre,count)) return false;
  if(pre>=root->val) return false;
  pre = root->val;
  ++count;
  if(!countNode(root->left,pre,count)) return false;
  return true;
}
//(2)計算每一個節點所建立的subtree 節點個數
void dfs(TreeNode* root, int& res){
    if(!root) return;
    int pre = INT_MAX;
    int count = 0;
    if(countNode(root,pre,count)){
        res = max(res,count);
        return;//如果是 validate BST, 則不用往下一層計算; 直接return
    }
    dfs(root->left,res);
    dfs(root->right,res);
}

//(3)計算所有subtree的valid count,並找出最大的那一個
int largestBSTSubtree(TreeNode* root){
    int res = 0;
    dfs(root,res);
    retur res;
}

