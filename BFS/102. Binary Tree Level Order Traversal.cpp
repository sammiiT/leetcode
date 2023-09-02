//===類似題===
314. Binary Tree Vertical Order Traversal
993. Cousins in Binary Tree
2471. Minimum Number of Operations to Sort a Binary Tree by Level
//===思路===
(*)BFS 算法

//====
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        res.push_back({});
        for(int i=q.size(); i>0 ;--i){//每一層的個數
            TreeNode* p = q.front();q.pop();
            res.back().push_back(p->value);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }
    return res;
}
