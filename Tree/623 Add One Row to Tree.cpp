class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode *tmp = new TreeNode(v);
            tmp->left = root;
            root = tmp;//更換root,新的root爲tmp, 所以將root指向tmp
            
        }else{
            helper(root,1,v,d);
        }
        return root;
    }
    
    void helper(TreeNode *root, int level, int v, int d){
        if(root==NULL) return;
        
        if((level+1)==d){
            TreeNode *tmp = root->left;
            root->left = new TreeNode(v);
            root->left->left = tmp;
            
            tmp = root->right;
            root->right = new TreeNode(v);
            root->right->right = tmp;
            return;
        }
        
        helper(root->left,level+1,v,d);
        helper(root->right,level+1,v,d);
    }
};