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

//========
    TreeNode* helper(TreeNode* root, int level, int isleft, int val, int depth){
//        if(!root) return NULL;
        if(!root && (level==depth)){//若是在最後一層
        }else if(!root){
            return NULL;
        }
      
        
        if(level==depth && isleft){
            TreeNode *tmp = new TreeNode(val);
            tmp->left = root;//連接
            return tmp;
        }else if(level==depth && !isleft){
            TreeNode *tmp = new TreeNode(val);
            tmp->right = root;//連接
            return tmp;
        }

//        if(root->left) root->left = helper(root->left, level+1, 1, val, depth);
//        if(root->right) root->right = helper(root->right, level+1, 0,val, depth);
         root->left = helper(root->left, level+1, 1, val, depth);//要最後一個level, 所不能用if(root->left)
         root->right = helper(root->right, level+1, 0,val, depth);

        
        
        return root;
    }
//1<=depth<=depth of tree + 1 要考慮第一個,和最後一個     
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* ret;
        ret = helper(root, 1,1,val,depth);
        return ret;
    }
