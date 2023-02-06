//===類似題===
531. Lonely Pixel I
765. Couples Holding Hands
934. Shortest Bridge
558. Logical OR of Two Binary Grids Represented as Quad-Trees
//===思路===
(*)pre-order算法 or inorder算法 都可以
- pre-order解法思路很直覺

- inorder思路很有技巧性;
--利用inorder特性可以有pre-order算法中求minvalue和maxvalue的效果


//=====inorder算法==
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int pre = -1;
        helper(root,res,pre);
        return res;
    }
    
  
    void helper(TreeNode *node, int& res, int& pre){
        if(!node) return;
        
        helper(node->left,res,pre);
        if(pre!=-1) res = min(res,abs(node->val-pre));
        pre = node->val;
        helper(node->right,res,pre);
        
    }
 };

//====pre-order算法======
int minvalue(TreeNode *root){
        if(root->left){
            return minvalue(root->left);
        }else{
            return root->val;
        }
}
int maxvalue(TreeNode *root){
        if(root->right){
            return maxvalue(root->right);
        }else{
            return root->val;
        }
}
  //每一個parent都往比較最後一個right, left leaf.  
void helper(TreeNode* root, int& mni){
        if(!root) return;        
        int deltal = INT_MAX, deltar = INT_MAX;
  
        if(root->left) deltal = abs(root->val - maxvalue(root->left));//比較最後一個leaf
        if(root->right) deltar = abs(root->val- minvalue(root->right));//比較最後一個leaf
        
        mni = min(mni,deltal);
        mni = min(mni,deltar);
        
        helper(root->left,mni);//往下找下一個minimum
        helper(root->right,mni);//往下找下一個minimum
}
    
int getMinimumDifference(TreeNode* root) {
        int mni = INT_MAX;
        helper(root,mni);
        return mni;
}

//===failed===
/*[1,0,48,null,null,12,49]會錯誤
int helper(TreeNode* root, int& res){
    if(!root) return 0;不能將NULL節點作考慮

    int l = helper(root->left,res);
    int r = helper(root->right,res);

    res = min(res,abs(root->val-l));
    res = min(res,abs(root->val-r));
    return root->val;
}*/

/*
[236,104,701,null,227,null,911]會錯誤
int helper(TreeNode* root, int& res){
    if(!root) return 0;
    int l,r;
    if(root->left) { 
        l = helper(root->left,res);
        res = min(res,abs(root->val-l));//要考慮left節點路徑中最大的數值
    }
    if(root->right){
        r = helper(root->right,res);
        res = min(res,abs(root->val-r));//要考慮right節點路徑中最小的數值
    }
    return root->val;
}*/



