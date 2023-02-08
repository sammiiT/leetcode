//===類似題===
621. Task Scheduler
1644. Lowest Common Ancestor of a Binary Tree II
314. Binary Tree Vertical Order Traversal
889. Construct Binary Tree from Preorder and Postorder Traversal
//===思路1===
(*)pre-order (DFS)
1.每進入一層, 都新建一個節點,會有4種情況
- 兩節點都NULL => 回傳 NULL 
- 一節點存在,一節點NULL => left NULL 或 right NULL
- 兩節點都存在 => 節點值相加

每次執行完, 都把新節點往上傳
//===思路2===
(*)pre-order (DFS)
-只討論 兩節點都存在的情況
-一節點存在,一節點不存在
如果root1不存在,回傳root2
如果root2不存在,回傳root1

//=========
class Solution {
public:
//---思路1-----
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
         return n;//心結點往上傳
    }
//-----思路2-----    
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
