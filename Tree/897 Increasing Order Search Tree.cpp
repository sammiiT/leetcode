class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *res=NULL, *last=NULL;
        
        helper(root,&last,&res);
        return res;
    }
    
    //recursive往上傳, last, res是副本,所以用pointer會出錯, 必須用pointer to pointer
    void helper(TreeNode* root, TreeNode** last, TreeNode** res){
        if(!root) return;
        
        helper(root->left,last,res);
        if(*res==NULL){
            *res=new TreeNode(root->val);
            *last = *res;
        }else{
            (*last)->right = new TreeNode(root->val);
            (*last) = (*last)->right;
        }
        helper(root->right,last,res);
        
    }
    
};