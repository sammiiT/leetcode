//===類似題===
898. Bitwise ORs of Subarrays
998. Maximum Binary Tree II
549. Binary Tree Longest Consecutive Sequence II
1717. Maximum Score From Removing Substrings

//===思路===
(*)post-order解法
1.當下節點做排列
   
   rt        L  <---回傳L給上層
  / \   =>    \    
 L   R         rt
                \
                 R

(*)需要用以下描述,不然 上層沒辦法連接下層更改的結果
root->left = helper(root->left);
root->right = helper(root->right);

用此方式會上下層節點沒辦法做連接
TreeNode* l = helper(root->left);
TreeNode* r - helper(root->right);

//=======
TreeNode* helper(TreeNode* root){
    if(!root) return NULL;
    root->left = helper(root->left);
    root->right = helper(root->right);
    TreeNode *left = root->left;
    TreeNode *right = root->right;

    if(left){
        root->left = NULL;
        TreeNode* t=left;
        while(t->right) t=t->right;
        t->right = root;
        return left;
    }
    return root;
}
TreeNode* increasingBST(TreeNode* root) {
    return helper(root);
}

//===思路2===
(*)inorder 概念求解
//====
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
