//===類似題====
889. Construct Binary Tree from Preorder and Postorder Traversal
1138. Alphabet Board Path
1695. Maximum Erasure Value
311. Sparse Matrix Multiplication

//===思路====
(*)找到每一個level的根結點之後, 分成左半部和右半部
(*)找到左半部第一個被遍歷的節點, 左半部最後一個被遍歷的節點
(*)找到右半部第一個被遍歷的節點, 右半部最後一個被遍歷的節點
TreeNode* helper(vector<int>& inorder, 
                 int iL,//inorder 左半部第一個被遍歷的點
                 int iR,//inorder 左半部最後一個被遍歷的點
                vector<int>& postorder, 
                 int pL, //postorder 左半部第一個被遍歷的節點
                 int pR)//postorder 左半部最後一個被遍歷的節點


TreeNode* helper(vector<int>& inorder, 
                 int iL,//inorder 右半部第一個被遍歷的點
                 int iR,//inorder 右半部最後一個被遍歷的點
                vector<int>& postorder, 
                 int pL, //postorder 右半部第一個被遍歷的節點
                 int pR)//postorder 右半部最後一個被遍歷的節點  
  

      1
     / \
    2   3
   /\   /\ 
  4  5  6 7  
inorder  = 4,2,5,1,6,3,7
post_order=4,5,2,6,7,3,1
(*)從root開始找起 => 1就是root, 再把tree分成左半部分和右半部分
(*)在postorder中, 最後一個數字,就是root

  
//======
TreeNode* helper(vector<int>& postorder,int pl,int pr,
		vector<int>& inorder, int il, int ir){
	if(pl>pr || il>ir) return NULL;
	int i = 0;//root
	
	for(i=0; i<ir; ++i){
		if(postorder[pr]==inorder[i]) break;
	}
	TreeNode* cur = new TreeNode(postorder[pr]);
	cur->left = helper(postorder, pl, pl+(i-il)-1, inorder, il, i-1); 
	cur->right= helper(postorder,pl+(i-il),pr-1,inorder,i+1,ir);
	return cur;
}

/*
inorder =   [9,3,15,20,7]
postorder = [9,15,7,20,3]
*/
TreeNode* helper(vector<int>& inorder, int iL,int iR,
                vector<int>& postorder, int pL, int pR) {
    if(iL>iR || pL>pR) return NULL;
    int i = 0;
    TreeNode* cur = new TreeNode(postorder[pR]);
    for(i=iL; i<iR; ++i) if(postorder[pR]==inorder[i]) break;

    cur->left = helper(inorder,iL,i-1, postorder,pL,pL+(i-iL)-1); 
    cur->right = helper(inorder,i+1,iR ,postorder,pL+(i-iL) ,pR-1);
    return cur;


}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
