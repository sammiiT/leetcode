class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
        if(!t1&&!t2) return NULL;
        
        TreeNode *n;
        if(!t1&&t2){
            n= new TreeNode(t2->val);
        n->left = mergeTrees(NULL,t2->left);
        n->right = mergeTrees(NULL,t2->right);
        }else if(t1&&!t2){
            n=new TreeNode(t1->val);
                n->left = mergeTrees(t1->left,NULL);
        n->right = mergeTrees(t1->right,NULL);
        }else{
            n = new TreeNode(t1->val+t2->val);
                n->left = mergeTrees(t1->left,t2->left);
        n->right = mergeTrees(t1->right,t2->right);
        }
         return n;
    }
    TreeNode* mergeTrees_OK(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        
        TreeNode *n = new TreeNode(0);
        n->val = t1->val+t2->val;
        n->left = mergeTrees(t1->left,t2->left);
        n->right= mergeTrees(t1->right,t2->right);
        return n;
        
    }
    
    //fail
    TreeNode *mergeTrees_2(TreeNode *t1,TreeNode *t2){
        if(!t1 && !t2) return NULL;

        TreeNode *n = new TreeNode(0);

        if(t1 && !t2){
                n->val = t1->val;
                n->left = mergeTrees_2(t1->left,NULL);
                n->right = mergeTrees_2(t1->right,NULL);
        }else if(!t1 && t2){
                n->val = t2->val;
                n->left = mergeTrees_2(NULL,t2->left);
                n->right =mergeTrees_2(NULL,t2->right);

        }else if(t1 && t2){
                n->val = t1->val + t2->val;
                n->left = mergeTrees_2(t1->left,t2->left);
                n->right =mergeTrees_2(t1->right,t2->right);
        }

        return n;

    }
    
};