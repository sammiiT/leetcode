//===類似題===
624. Maximum Distance in Arrays
993. Cousins in Binary Tree
1650. Lowest Common Ancestor of a Binary Tree III
2049. Count Nodes With the Highest Score
//===思路1==== 
(*)停在目標level的"前"一層做運算
- 新增節點連接下一層, 並指派給當下節點的left 和right
      O      1
     / \
    O   O    2
   / \ / \ 
  O  O O  O  3
    
depth = 3 ;停在level_2做運算 
-在level_2做運算,要一次連結兩個節點, left和right; left和right個別由一個節點做連結
-連接下一層,還要連結上一層    
//======
TreeNode* helper1(TreeNode* root, int level, int val, int depth){
    if(!root) return root;
    if(level==depth-1){
        TreeNode* l =new TreeNode(val);
        TreeNode* r =new TreeNode(val);
        l->left = root->left;
        r->right = root->right;
        root->left = l;
        root->right = r;
        return root;
    }    

    root->left = helper1(root->left,level+1,val,depth);
    root->right = helper1(root->right,level+1,val,depth);
    return root;
}
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(depth==1){
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }
    return helper1(root,1, val, depth);
}

//===思路2
-停在目標level上做運算
-把
TreeNode* helper(TreeNode* root, int val, int depth, bool isleft){
    if(depth==1){
        TreeNode* node = new TreeNode(val);
        if(isleft) node->left = root;
        else node->right = root;
        return node;
    }
    if(!root) return NULL;//放在最前面會出錯, 因為如果depth是最後一層;新增的一層,放在前面會出錯
    
    root->left = helper(root->left, val, depth-1, true);
    root->right = helper(root->right, val, depth-1,false);
    return root;
}
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    return helper(root,val,depth,true);
}

//===    
TreeNode* helper(TreeNode* root, int level, int isleft, int val, int depth){
//        if(!root) return NULL;
    if(!root && (level==depth)){
    }else if(!root){ return NULL; }
       
    if(level==depth && isleft){
        TreeNode *tmp = new TreeNode(val);
        tmp->left = root;//連接
        return tmp;
    }else if(level==depth && !isleft){
        TreeNode *tmp = new TreeNode(val);
        tmp->right = root;//連接
        return tmp;
    }

    root->left = helper(root->left, level+1, 1, val, depth);
    root->right = helper(root->right, level+1, 0,val, depth);        
    return root;
}
//1<=depth<=depth of tree + 1 要考慮第一個,和最後一個     
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    TreeNode* ret;
    ret = helper(root, 1,1,val,depth);
    return ret;
}



//=========
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
