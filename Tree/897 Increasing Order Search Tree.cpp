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

用此方式會上下層節點沒辦法做連接: 
TreeNode* l = helper(root->left);
TreeNode* r - helper(root->right);

上下層沒辦法做連接, 所以會造成如下錯誤: 少了節點7
Input root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output =  [1,null,2,null,3,null,4,null,5,null,6,null,8,null,9]
Expected= [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
     6                                                               7  6
      \                                                               \  \ 
       8   => 8節點會在此level計算為      7  => 回傳7節點指標給6節點層     \- 8 
      / \                                 \                                 \
     7   9                                 8                                 9
                                            \
                                             9
                                             
(*)但因為沒有做連結,6節點還是連結到8, 而7節點已經改變原來位址, 導致輸出沒有7 
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
