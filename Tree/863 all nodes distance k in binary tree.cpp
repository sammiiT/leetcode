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

//===思路2===
(*)用post-order找出每一個節點的parent
TreeNode* map_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& ump){
    if(!root) return root;
    root->left = map_parent(root->left,ump);
    root->right = map_parent(root->right,ump);
    if(root->left) ump[root->left] = root;
    if(root->right) ump[root->right] = root;
    return root;
}

(*)找出距離target為k的節點
(*)unordered_map<TreeNode*,int>& visited是為了防止往parent找時,找到之前遍歷的節點
void helper(TreeNode* target, 
            int k, 
            unordered_map<TreeNode*,int>& visited,
            unordered_map<TreeNode*,TreeNode*>& ump,
            vector<int>& res){

    if(!target) return;
    if(visited.count(target)) return;
    if(k==0){
        res.push_back(target->val);
        return;
    }

    visited[target]=1;
    if(target->left) helper(target->left,k-1,visited,ump,res);
    if(target->right) helper(target->right,k-1,visited,ump,res);

    if(ump.count(target)){
        helper(ump[target], k-1, visited, ump, res);
    }
}


vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*,TreeNode*> ump;
    unordered_map<TreeNode*,int> visited;
    vector<int> res;

    map_parent(root,ump);
    helper(target,k,visited,ump,res);

    return res;
}

//===寫法3 ====
void dfs(TreeNode* target, 
        int k, 
        unordered_map<TreeNode*,TreeNode*>& ump,
        unordered_map<TreeNode*,int>& visited,
        vector<int>& res){
    
    if(target==NULL || visited[target]==1) return;
    if(k==0) {
        res.push_back(target->val);
        return;
    }

    visited[target]=1;
    dfs(target->left,k-1,ump,visited,res);
    dfs(target->right,k-1,ump,visited,res);
    if(ump.count(target))
        dfs(ump[target],k-1,ump,visited,res);
}

void find_parent(TreeNode* root, 
                TreeNode* parent, 
                unordered_map<TreeNode*,TreeNode*>& ump,
                unordered_map<TreeNode*,int>& visited){
    if(root==NULL) return;
    
    ump[root]=parent;
    visited[root]=0;
    if(root->left) find_parent(root->left, root, ump,visited);
    if(root->right) find_parent(root->right, root, ump,visited);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> ump;
    unordered_map<TreeNode*, int> visited;
    vector<int> res;

    visited[root]=0;
    find_parent(root->left,root,ump,visited);
    find_parent(root->right,root,ump,visited);

    dfs(target,k,ump,visited,res);
    return res;
}



