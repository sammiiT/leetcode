//===類似題===
766. Toeplitz Matrix
1992. Find All Groups of Farmland
272. Closest Binary Search Tree Value II
417. Pacific Atlantic Water Flow
//===思路===
//====
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
