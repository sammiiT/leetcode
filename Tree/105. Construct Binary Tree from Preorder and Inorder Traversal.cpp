//===類似題===
106. Construct Binary Tree from Inorder and Postorder Traversal


//===思路===
(*)preorder找到 root節點之後, 將其分成左半部分,右半部分

      1
     / \
    2   3
   /\   /\ 
  4  5  6 7

         0 1 2 3 4 5 6
preorder=1,2,4,5,3,6,7
inorder =4,2,5,1,6,3,7 

(*)是以inorder的index做計算, 所以preorder索引在計算時, 要加上 (i-il)
(*)inorder直接用其index做計算,所以不用對其做(i-il)運算    
cur->left = helper(preorder,pl+1,i-il, inorder,il,i-1) //左半邊
cur->right = helper(preorder,pl+(i-il)+1, pr, inorder,i+1,ir) //右半邊



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
