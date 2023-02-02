//===類似題====
111. Minimum Depth of Binary Tree
582. Kill Process
285. Inorder Successor in BST
2322. Minimum Score After Removals on a Tree

//===思路===
(*)用maximum depth的思路求解
-每階層的post-order求算完,先計算一次左右兩子節點所構成的depth差值. 並與每層比較,紀錄最大差值
-回傳最大的depth給上一層,繼續做運算比較

//=======
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
    
//------錯誤的helper------- 
    void _helper(TreeNode* root, int level, int& lmax, int& lmin){
        if(!root) return;
        if(root->left) helper(root->left, level+1, lmax, lmin);
        if(root->right) helper(root->right, level+1, lmax, lmin);
        lmin = min(lmin,level);//會錯誤, 因為每回一層, level就會減一, 所以min會一直跳到最原始的level數值
                               //所以要找到second maximum 
        lmax = max(lmax,level);
    }
    bool isBalanced(TreeNode* root) {
        int lmax = INT_MIN;
        int lmin = INT_MAX;
        helper(root,0,lmax,lmin);
        return (lmax-lmin<=1);//((lmax-lmin)>1)?false:true;
    }   
     
     
     
};
