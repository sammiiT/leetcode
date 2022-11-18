class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;
    }
    
    
    void helper(TreeNode *root, int level, vector<int>& res){
        if(!root) return;
        
        if(res.size()==level) res.push_back(INT_MIN);
        
        res[level] = max(res[level],root->val);
        
        helper(root->left, level+1, res);
        helper(root->right, level+1, res);
    }
};

void helper(TreeNode* root, int level, vector<int>& res){
        if(!root) return;
        
        if(level==res.size()){
            res.push_back({});  
            res[level] = root->val;
        }else{
            res[level] = max(res[level],root->val);
        } 
        
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
}   
vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        
        return res;
}
