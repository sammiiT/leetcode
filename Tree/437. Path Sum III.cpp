//===類似題===
438. Find All Anagrams in a String
666. Path Sum IV
687. Longest Univalue Path
//===思路===
(*)pre-order (DFS)
1.(減法), 每進入下一層,就對targetSum-root->val; 如果等於0,代表滿足題意,解加1
2.因為不用從root開始算起,所以每次遍歷一次tree之後,就往下一階層,將其節點當成新的root節點做運算

   O <--從這一點遍歷                             O
  / \                     第二次計算            / \
 L   R                     =======>           L   R   <---從L,R節點當作root做運算,遍歷所有tree node
    / \                                          / \
   P   Q                                        P   Q 
//=======
void helper(TreeNode* root,long targetSum, int& res){
    if(!root) return;
    targetSum-=root->val;
    if(targetSum==0) res++;    

    if(root->left) helper(root->left,targetSum,res);
    if(root->right) helper(root->right,targetSum,res);
}

void each(TreeNode* root, long targetSum,int& res){
    if(!root) return;
    helper(root,targetSum,res);
    each(root->left,targetSum,res);
    each(root->right,targetSum,res);        
}

    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        each(root,targetSum,res);
        return res;
    }
