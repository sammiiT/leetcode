class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        int mx =INT_MIN;
        vector<int> res;
        helper(root,m,mx);
        for(auto a:m){
            if(a.second==mx){
                res.push_back(a.first);
            }
        }
        
        return res;
    }
    
    void helper(TreeNode* root,unordered_map<int,int>& m,int& mx){
        if(root==NULL) return;
    
        helper(root->left,m,mx);
        mx = max(mx,++m[root->val]);
        helper(root->right,m,mx);
    }
};