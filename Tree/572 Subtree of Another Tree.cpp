class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL) return false;    
        if(isSame(s,t)) return true;
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    
bool isSame(TreeNode *s,TreeNode *t){
if(!s && !t) return true;
if(!s&&t || s&&!t || s->val!=t->val) return false;
return isSame(s->left,t->left) && isSame(s->right,t->right);
    
   
}
    
    
//         bool isSubtree(TreeNode* s, TreeNode* t) {
//         if(s==NULL) return false;
//         if(isSame(s,t)) return true;
        
//         return isSubtree(s->left,t)||isSubtree(s->right,t);
//     }
    
//     bool isSame(TreeNode* s,TreeNode* t){
//         if(!s&&!t) return true;
//         if(s&&!t || !s&&t || s->val!=t->val) return false;
        
//         return isSame(s->left,t->left) &&           isSame(s->right,t->right);
//     }

 //==================================
bool isSame(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!q&&p || q&&!p || p->val!=q->val) return false;
        return isSame(p->left,q->left) && isSame(p->right,q->right);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSame(root,subRoot)) return true;   
//        return isSame(root->left,subRoot)||isSame(root->right,subRoot);//錯誤描述,
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);        
}   
    
    
    
};
