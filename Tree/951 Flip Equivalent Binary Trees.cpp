class Solution{
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        
        if(!root1&&root2 || root1&&!root2 || root1->val!= root2->val) return false;
        
        return (flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left))
            ||(flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right));

        //中間可以不對調,或可對調, 所以要加上(root1->left,root2->left),(root1->right,root2->right)
        // logic operator運算順序 && , ||
    }
};