class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<vector<int>> res;
        vector<int> out;
        helper(root,0,res);
        
        for(int i=0;i<res.size();++i){
            
            out.push_back(res[i].back());
        }
        return out;
    }
    
    //利用level order, 將每一個level的數列列出來, 再將每一數列的最後一個數值取出
    void helper(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root) return;
        
        if(res.size()==level) res.push_back({});
        res[level].push_back(root->val);
        
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
    }
};