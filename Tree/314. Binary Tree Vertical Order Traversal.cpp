//===類似題===
987. Vertical Order Traversal of a Binary Tree
//===思路===
(*)使用map<T>
- map會依照key數值的大小作排列 ;且之後key對應的值,會覆蓋之前key對應的值
- 每次搜尋都會在logn時間之內完成
- 定義map<int,vector<int>>//<x_idx, x_idx上所有的數值>
- x_idx上的所有數值,就是vertical element所構成的陣列

(*)使用queue<T>
- 定義queue<pair<int,TreeNode*>>//<x_idx, x_idx對應的TreeNode*>
-以preorder方式push至quque, 則vertical順序會滿足題意

//=======
vector<vector<int>> verticalOrder(TreeNode* root){
  vector<vector<int>> res;
  map<int,vector<int>> m;//x-idx, TreeNode value on the index
  queue<pair<int,TreeNode*>> q;//x-idx, TreeNOde
  q.push({0,root});
  
  while(!q.empty()){
      auto a = q.front();
      q.pop();
/* a.first = index
   a.second = TreeNode */    
      m[a.first].push_back(a.second->val);//同一x_idx的value所構成的陣列
      if(a.second->left) q.push(a.first-1, a.second->left);//left的index是parent位置-1
      if(a.second->right) q.push(a.first+1, a.second->right);//right的index是parent位置+1
  }
  for(auto a:m){
/*
a.first = int
a.second = vector<int>
*/  
    res.push_back(a.second);//把所有相同index的陣列加到res
  }
  return res;
}
