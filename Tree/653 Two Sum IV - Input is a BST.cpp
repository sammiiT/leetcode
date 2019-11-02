class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        int res = 0;
        unordered_map<int,int> m;
        // helper(root,k,m,res);
        helper_2(root,k,m,res);
        
        return res?true:false;
    }
    
    
    void helper(TreeNode* root,int k,unordered_map<int,int>& m,int& res){
        if(!root) return;
        
        helper(root->left,k,m,res);
        if(m.count(k-root->val)){
            res = 1;
            return;
        }
        m[root->val]++;
        
        helper(root->right,k,m,res);
    }
    
    
    void helper_2(TreeNode* root, 
                  int k, 
                  unordered_map<int,int>& m,
                  int &res){
        if(!root) return;
        if(m.count(k-root->val)){
            res =1;
            return;
        }
        m[root->val]++;
        helper(root->left,k,m,res);
        helper(root->right,k,m,res);
        
    }
};

