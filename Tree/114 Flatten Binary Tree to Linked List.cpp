//===類似題===
115. Distinct Subsequences
430. Flatten a Multilevel Doubly Linked List
1660. Correct a Binary Tree
//===思路===
(*) post-order (DFS)
1.先找到最後一個節點(最後一個level)
-因為其child都是NULL, 所以運算後只會回傳一個node給上層
-最後一個節點也可以用下述運算

2.分析倒數第二個level,左右兩端都有節點
-記錄右側節點; tmp = root->right
-指向right的pointer指向左側節點,將指向左側節點的pointer指向NULL
-遍歷新的右側極點到底, 將最底端的右側節點重新指向tmp

分析倒數第二level   記錄R,並將right指標指向L   將最後一個right指標,指向原來記錄的R
     O                     O                   O
    / \   =>              / \           =>   /  \
   L   R               NULL  L             NULL  L
                                                  \
				           	   R
					 
     O
    / \   =>用post-order(DFS), 每一次的left都會排列如左圖
   O   R
    \
     L
      \
       R
//========
void helper3(TreeNode* root) {
    if(!root) return ;
    helper3(root->left);
    helper3(root->right);
    if(root->left){
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right) root = root->right;
        root->right = tmp;
    }
}

void helper0(TreeNode* root){
    if(!root) return;
    helper0(root->left);
    helper0(root->right);
    
    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = NULL;
    while(root->right){//
    	root = root->right;
    }
    root->right = tmp;
}

//===思路====
class Solution {
public:
	//post-order概念
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);
        
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        while(root->right) root = root->right;
        root->right = tmp;
        
    }
};

      1
     / \
    2   5
   / \   \
  3   4   6

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

//----錯誤; 原因----
    void helper(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right) return;
//        if(!root->left && root->right) return;//此描述錯誤
         if(root->left) helper(root->left);
        if(root->right) helper(root->right);
        
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        while(root->right){
            root = root->right;
        }
        root->right = tmp;
    }

if(!root->left && root->right) return; 如果right底下還有child,其底下的child不會做運算(swap).








