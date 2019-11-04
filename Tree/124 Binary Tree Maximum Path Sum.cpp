/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root,res);
        return res;
    }
    
    
    int helper(TreeNode *root, int& res){
        if(!root) return 0;
        
        int l=0,r=0;//沒設定初始值, 以下的描述會出現錯誤
        if(root->left) l = max(helper(root->left,res), 0);//如果left為負值,則用0來計算,截斷
        if(root->right) r= max(helper(root->right,res), 0);//如果right為負值,則用0來計算截斷
    
        res = max(res,l+r+root->val);
        return max(l,r)+root->val;
        
        
//[1,-2,3]
// 3
// 4        
/*
    1
 -2   3


*/     
        
        
/*
    [-2,6,null,0,6]

*/        
        
        
        
        
    }
};


// if(!root) return INT_MIN;
        
//         int l=0,r=0;
//         if(root->left)  l = helper(root->left, res);
//         if(root->right) r = helper(root->right,res);
        
        
//         if(l>=0 && r >=0 && root->val >=0){
//             res = max(res,root->val+l+r);
//         }else if(l>=0 && r<0){
//             res = 
//         }
        
        
//         res = max(res, root->val+l+r);
//         res = max(res, root->val);
//         return (l>=r)? (l+root->val) : (r+root->val); 