class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int> p;
        p.first = -1;
        helper(root,0,p);
        return p.second;
    }

    void helper_OK(TreeNode *root,int level,pair<int,int>& p){
        if(!root) return;
        
        if(root->left) helper(root->left,level+1,p);
        
        if(level>p.first){
            p.first = level;
            p.second = root->val;
        }        
        if(root->right) helper(root->right,level+1,p);
    }
    
    
    void helper(TreeNode* root, int level, pair<int,int>& res){
        if(!root) return;
        
        helper(root->left,level+1,res);
        if(level>res.first){
            res.second = root->val;
            res.first = level;
        }
        helper(root->right,level+1,res);
    }

};


void helper(TreeNode* root, int level, vector<vector<int>>& v){
        if(!root) return;
        if(level==v.size()) v.push_back({});
        v[level].push_back(root->val);
        
        helper(root->left,level+1,v);
        helper(root->right,level+1,v);
}

int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,0,res);
        
        return res[res.size()-1].at(0);
}
