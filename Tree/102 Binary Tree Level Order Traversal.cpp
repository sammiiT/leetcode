//===類似題===
103. Binary Tree Zigzag Level Order Traversal
314. Binary Tree Vertical Order Traversal
993. Cousins in Binary Tree
2471. Minimum Number of Operations to Sort a Binary Tree by Level
//===思路===
(*) tree level_order 遍歷
1. 每一個level都是一個陣列
2. 每進入新的下一層, 判斷level是否等於res.size(), 如果等於,代表要新增一個陣列

//======
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,0,res);
        
        return res;
    }
    
    void helper(TreeNode* root, int level, vector<vector<int>>& res){
        if(root==NULL) return;
        if(res.size()==level) res.push_back({});
        res[level].push_back(root->val);
        
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
        
    }
};
//====思路2====
(*)BFS算法

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        res.push_back({});
        for(int i=q.size(); i>0 ;--i){//每一層level的個數
            TreeNode* p = q.front();q.pop();
            res.back().push_back(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }
    return res;
}


