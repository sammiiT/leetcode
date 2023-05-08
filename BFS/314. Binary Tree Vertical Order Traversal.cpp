//===


//===思路===
(*)BFS

//===

vector<vector<int>> verticalOrder(TreeNode* root) {
  vector<vector<int>> res;
  map<int,vector<int>> mp; //y, [level]
  queue<pair<int,TreeNode*>> q;
  q.push({0,root});
  
  while(!q.empty()){
    auto tmp = q.front(); q.pop();
    mp[tmp.first].push_back(tmp.second->val);
    
    if(tmp.second->left) q.push({tmp.first-1,tmp.second->left});
    if(tmp.second->right) q.push({tmp.first+1, tmp.second->right});
  }
  
  for(auto a: mp){
    res.push_back(a.second);
  }
  return res;
}
