class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preOrder(root,res);
        return res;
    }
    
    void preOrder(Node* root, vector<int>& res){
        if(!root) return;
        
        res.push_back(root->val);
        for(Node* n: root->children){
            preOrder(n,res);
        }
    }
    
};