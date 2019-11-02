class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    
    void helper(Node *root, vector<int>& res){
        if(!root) return;
        for(Node* n:root->children){
            helper(n,res);
        }
                 res.push_back(root->val);
    }
};