//===類似題===
544. Output Contest Matches
1522. Diameter of N-Ary Tree
2246. Longest Path With Different Adjacent Characters
//===思路===
(*)題議: 路徑可以或不用經過root
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

(*)post-order算法
-每一次運算會回傳左節點的長度,和右節點的長度
-運算完之後, 比較左右長度,回傳較長的那一個; return max(l,r)+1; 加1的目的是當下那一層的節點,也算一個個數, 回傳給上一層
-最長diameter是(r+l); 每一層都會計算一次(r+l)
//=====
int helper0(TreeNode* root, int& res){
    if(!root) return 0;
    int l = 0,r = 0;
    
    if(root->left) l = helper0(root->left, res);
    if(root->right) r = helper0(root->right, res);

//回到原來的階層,比較子路徑L和R,哪一個比較長
    res = max(res, 1+r+l);
    return (l>r)?(l+1):(r+1);
  //  return 1 + max(l,r);//這一行描述也可以
}

int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    helper0(root,res);
    return res-1;//減1 是因為不包含"解"最上面的父節點   
}

//=======================
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root,res);
        return res;
    }
    int diameterOfBinaryTree_OK(TreeNode* root) {
        int res = 0;
        int l=0,r=0;
        // if(!root) return 0;
        if(root && root->left) l=maxDepth(root->left,res);
        if(root && root->right) r=maxDepth(root->right,res);
        
        res = max(l+r,res);
        return res;
    }
    
    int maxDepth(TreeNode *root, int& res){
        if(root==NULL) return 0;
        int l=0,r=0;
        
        if(root->left) l = maxDepth(root->left,res);
        if(root->right) r= maxDepth(root->right,res);
        
        res = max(l+r, res);
        return 1 + max(l,r);
    }
    
    
    int maxDiameter(TreeNode *root, int& res){
        if(!root) return 0;
        
        int l=0,r=0;
        if(root->left) l = maxDiameter(root->left,res);
        if(root->right) r = maxDiameter(root->right,res);
        
        // res = max(res,1+l+r);不用此描述,因為是討論距離,不是個數
        res = max(res,l+r);
        return  1+max(l,r);
    }
    
    int helper(TreeNode* root,int& res){
        if(!root) return 0;
        int l = helper(root->left,res);
        int r = helper(root->right,res);
        
        res = max(res,l+r);
        return 1+max(l,r);
    }
};
