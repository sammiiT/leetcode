class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        //helper(root,res);
        helper_3(root,res);      
/*        
   // use helper_2()-----     
        if(!root) return 0;
        helper_2(root->left,1,res);
        helper_2(root->right,0,res);
   // use helper_2()------     
*/        
        return res;
    }
    
    void helper_3(TreeNode *root, int& res){
        if(!root) return;
        
        if(root->left){//為了要滿足root->left->left不會發生 segment fault
            if(!root->left->left && !root->left->right){
                res+=root->left->val;
                // return;//不能有這一描述,因為還有right沒有運算到
            }else{
                helper_3(root->left,res);
            }
        }
        helper_3(root->right,res);
        
    }
    
    void helper_2(TreeNode* root, int isLeft ,int& res){
        if(!root) return;
        helper_2(root->left,1,res);
        if((!root->left) && (!root->right) && isLeft){
            res+=root->val;
        }
        helper_2(root->right,0,res);
    }
    
    
    void helper(TreeNode *root, int& res){
        if(root==NULL) return;
        
        if(root->left){
            if(root->left->left==NULL && root->left->right==NULL){
                res = res + root->left->val;    
            }else{
                helper(root->left,res);
            }
        }
        
        if(root->right){
            helper(root->right,res);
        }
    }
    
};