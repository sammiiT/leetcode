//====類似題====
223. Rectangle Area
270. Closest Binary Search Tree Value

//===思路===
1. post order概念, 先記錄兩個子節點, 再紀錄父節點
2.先運算兩個子節點; 先進入遞迴
3.再運算父節點, 當下層+1,視為父節點
//=======
class Solution {
public:
    int countNodes_(TreeNode* root) {
        if(root==NULL) return 0;
        
        int count = 0;
        count+=countNodes(root->left);
        count+=countNodes(root->right);
        
        return 1+count;
        
    }
    
    int countNodes(TreeNode *root){
        if(!root) return 0;
        
        int l=0,r=0;
        if(root->left) l = countNodes(root->left);
        if(root->right) r= countNodes(root->right);
        
        return 1+r+l;
    }
};
//========================
int helper2(TreeNode* root){//postorder
    if(!root) return 0;
    return 1+helper2(root->left)+helper2(root->right);
}
//=========================
void preorder_helper3(TreeNode* root,int& res){//preorder
    if(!root) return;
    res+=1;
    preorder_helper3(root->left,res);
    preorder_helper3(root->right,res);
}
int helper3(TreeNode* root){
    int res = 0;
    preorder_helper3(root,res);
    return res;
}
//========================
void inorder_helper4(TreeNode* root, int& res){//inorder
    if(!root) return;
    inorder_helper4(root->left,res);
    res+=1;
    inorder_helper4(root->right,res);
}
int helper4(TreeNode* root){
    int res = 0;
    inorder_helper4(root,res);
    return res;
}


