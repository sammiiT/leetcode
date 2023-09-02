//===類似題===
104. Maximum Depth of Binary Tree
987. Vertical Order Traversal of a Binary Tree
490. The Maze
1443. Minimum Time to Collect All Apples in a Tree

//===思路=====
(*)tree level order trasverse
(*)這一題是用zigzag排列
1.將level做奇偶判斷, 
-偶數就push_back
-奇數就insert, insert至begin()
//=====
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,0,res);
        return res;
    }
    
    void helper(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root) return;
        
        if(level==res.size()) res.push_back({});
        if(level%2){//奇數
            res[level].insert(res[level].begin(),root->val);
        }else{//偶數
            res[level].push_back(root->val);
        }
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
    }
};
//===思路2===
(*) BFS 解法

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

