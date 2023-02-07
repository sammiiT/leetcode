//===類似題===
609. Find Duplicate File in System
536. Construct Binary Tree from String
//===思路====
(*)preorder (DFS)
(*)如果遇到(!root->left && root->right),無左節點,有右節點 
-需加入保留"()"
//=====
class Solution {
public:
    string tree2str(TreeNode* t) {
        string s;
        if(!t) return s;
        helper_2(t,s);
        s.pop_back();
        s.erase(0,1);
        
        return s;
    }
    void helper_2(TreeNode* root, string& s){
        if(!root) return;
        s = s+"(";
        s = s+to_string(root->val);
        if(!root->left && root->right){
            s = s + "()";
        }
        helper_2(root->left,s);
        helper_2(root->right,s);
        s = s+")";
    }
    string tree2str_ok(TreeNode* t) {
        string s;
        if(!t) return s;
            
        helper_ok(t, t->right?1:0, s);
        s.pop_back();
        s.erase(0,1);
        return s;
    }
    
    void helper_ok(TreeNode *root, int r, string& s){
        if(!root){
            if(r==1) s=s+"()";
            return;
        }
        s=s+"(";
        s=s+to_string(root->val);
       // helper(root->left,root->right?1:0,s);
        helper_ok(root->left,(root->right!=NULL),s);
        helper_ok(root->right,0,s);
        s=s+")";
    }
};
