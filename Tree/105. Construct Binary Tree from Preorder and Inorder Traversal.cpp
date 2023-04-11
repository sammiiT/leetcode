//===類似題===
106. Construct Binary Tree from Inorder and Postorder Traversal


//===思路===
(*)preorder找到 root節點之後, 將其分成左半部分,右半部分


//=====
TreeNode* helper(vector<int>& preorder, int pL, int pR, vector<int>& inorder, int iL,int iR){
    if(pL>pR || iL>iR) return NULL;
    int i = 0;

    for(i = iL; i<=iR; ++i){
        if(preorder[pL]==inorder[i]) break;
    }
    
    //(i-iL)是下一個pL要跳的距離
    TreeNode* cur = new TreeNode(preorder[pL]);
    cur->left = helper(preorder,pL+1, pL+(i-iL), inorder,iL, i-1);//left partition
    cur->right = helper(preorder,pL+(i-iL)+1, pR, inorder,i+1,iR);//right partition
    return cur;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}
