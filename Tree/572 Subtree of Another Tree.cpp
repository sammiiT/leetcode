//===類似題===
573. Squirrel Simulation
250. Count Univalue Subtrees
//===思路===
(*)算法同isSameTree,但要以每一個節點做遍歷
1. match函數就是 isSameTree()
2.每次執行完一次match函數,就必須再以left,和right為根結點,繼續再執行一次match    
3.isSubtree就是每次以child節點作為根節點, 再執行一次match

(*)因為是subtree,所以會遍歷到"最後一個節點"...
"並不是中途一串結點相同"
//=======
bool match(TreeNode* root, TreeNode* subRoot){
    if(!root && !subRoot) return true;
    if((!root&&subRoot) || (root&&!subRoot) || (root->val!=subRoot->val)) return false;
    return match(root->left,subRoot->left) && match(root->right,subRoot->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root) return false;//沒有此項,會有access NULL pointer
    if(match(root,subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot);      
//  return isSubtree(root->left, subRoot->left) || isSubtree(root->right,subRoot->right);//比較錯誤,應該是比較原來subRoot
}
//===思路2===
(*)展開Tree的算法,將每一個節點展開,並記錄到queue<TreeNode*>
//=====
bool isSubtree(TreeNode* root, TreeNode* subRoot){
    if(!root) return false;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* t = q.front();q.pop();
        if(match(t,subRoot)) return true;
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
    return false;    
}

//======
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
