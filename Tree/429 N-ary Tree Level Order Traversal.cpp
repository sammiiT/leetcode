class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        helper(root, 0,res);
        return res;
    }
    
    void helper(Node* root, int level, vector<vector<int>>& res){
        if(!root) return;
    
        if(res.size()==level) res.push_back({});
        res[level].push_back(root->val);
    
        for(Node* n : root->children){
            helper(n,level+1,res);
        }
    }
};