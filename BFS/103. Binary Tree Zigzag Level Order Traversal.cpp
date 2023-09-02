//===類似題===
207. Course Schedule
841. Keys and Rooms
1367. Linked List in Binary Tree
//===思路===
(*)BFS 算法
//===
vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        res.push_back({});
        for(int i=q.size(); i>0; --i){
            TreeNode* p=q.front();q.pop();
            if(res.size()%2) res.back().push_back(p->val);
            else res.back().insert(res.back().begin(),p->val);
            
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }
    return res;
}
