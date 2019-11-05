class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        unordered_map<TreeNode*,TreeNode*> m;
        unordered_set<TreeNode*> visited;
        
        findParent(root,m);
        helper(target,K,visited,m,res);
        return res;
        
    }
    
    //提供往上找的路徑
    void findParent(TreeNode *root, unordered_map<TreeNode*,TreeNode*>& m){
        if(!root) return;
        
        if(root->left)  m[root->left] = root;
        if(root->right) m[root->right] = root;
        
        findParent(root->left,m);
        findParent(root->right,m);
    }

    void helper(TreeNode* root, int k, unordered_set<TreeNode*>& visited, unordered_map<TreeNode*,TreeNode*>&m ,vector<int>& res){
        if(!root) return;
        if(visited.count(root)) return;
        
        visited.insert(root);
        
        if(k==0) {
            res.push_back(root->val);
            return;
        }
        
        if(root->left) helper(root->left, k-1,visited,m,res);
        if(root->right) helper(root->right,k-1,visited,m,res);
        
        //往上找
        if(m[root]) helper(m[root],k-1,visited,m,res);
        
    }

};
