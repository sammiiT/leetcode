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
//====寫法2===
(*)預先先將 滿足條件的節點放到map中
-上面寫法是將 quueue中的 元素pop出來之後, 才將元素節點位置放到map中
-因為每一個節點都是滿足題目條件, 所以才會在q.pop()之後將元素節點位置放到map
-如果節點不滿足條件就放入queue中, 會造成time-limited-exceeded; 
因為不滿足條件的元素和滿足條件的元素都在queue; 會造成部必要的運算

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    map<int,vector<int>> mp;
    queue<pair<TreeNode*,int>> q;//位置

    q.push({root,0});
    mp[0].push_back(root->value);
    
    while(!q.empty()){
        pair<TreeNode*,int> p = q.front();q.pop();
        if(p.first->left){
            q.push({p.first->left, p.second-1});
            mp[p.second-1].push_back(p.first->left->value);
        }
        if(p.first->right){
            q.push({p.first->right,p.second+1});
            mp[p.second+1].push_back(p.first->right->value);
        }
    }
    
    for(auto it:mp){
        res.push_back(it.second);
    }
    return res;
}

