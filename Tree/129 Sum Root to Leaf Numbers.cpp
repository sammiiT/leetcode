class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        helper(root,"",res);
        return res;
    }
    
    void helper(TreeNode* root,string s ,int& res){
        if(!root) return;
        
        s+=to_string(root->val);
        if((!root->left)&&(!root->right)){
            res += stoi(s);
        }else{
            helper(root->left,s,res);
            helper(root->right,s,res);
        }
    }
    
    
};