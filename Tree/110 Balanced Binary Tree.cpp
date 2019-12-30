class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // if(root==NULL) return true;
        // if(checkBalanced(root)==-1) return false;
        // return true;
        int res=0;
        helper(root,res);
        return (res>1)?false:true;
    
    }
    
    int checkBalanced(TreeNode *root){
        if(root==NULL) return 0;
        
        int l=0,r=0;
        if(root->left) l = checkBalanced(root->left);
        if(l==-1) return -1;//中途就截斷
        
        if(root->right) r = checkBalanced(root->right);
        if(r==-1) return -1;//中途就截斷
        
        int diff=abs(l-r);
        if(diff>1) return -1;//中途就截斷
        else return 1+max(l,r);
        
    }
    
    //post-order算法
    int helper(TreeNode* root, int &res){
        if(!root) return 0;
        int l=0,r=0;
        
        if(root->left) l = helper(root->left, res);
        if(root->right) r = helper(root->right,res);
     
        res = max(abs(l-r),res);//當下節點運算,包含其下節點總和
        
        return 1+max(l,r);//當下節點運算,包含其下節點總和
    }
    
};