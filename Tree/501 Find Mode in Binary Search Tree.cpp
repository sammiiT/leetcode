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

void helper(TreeNode* root, int& mval, unordered_map<int,int>& map){
        if(!root) return;
        
        map[root->val]+=1;
        mval = max(mval, map[root->val]);
        
        helper(root->left, mval, map);
        helper(root->right, mval, map);
}
    
    
vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> map;
        vector<int> res;
        int mval = 0;
        helper(root, mval, map);
        for(auto& it:map){
            if(it.second==mval){
                res.push_back(it.first);
            }
        }
        return res;
}
