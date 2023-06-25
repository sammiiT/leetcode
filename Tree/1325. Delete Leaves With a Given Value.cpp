//===類似題===
2057. Smallest Index With Equal Value
1145. Binary Tree Coloring Game
1916. Count Ways to Build Rooms in an Ant Colony
250. Count Univalue Subtrees

//===思路===
Leaf: 沒有子節點的節點
(*)用post-order
(*)到最後一個節點時,判斷值是否等於target
- 是leaf且等於target, 回傳NULL
- 是leaf但不等於target, 則回傳root
- 不是leaf, 則回傳root

(*)每一次leaf的運算結果, 都會成為下一個節點的運算依據

  
//=====
TreeNode* helper(TreeNode* root, int target){
    if(!root) return NULL;

    root->left = helper(root->left,target);
    root->right = helper(root->right,target);
    
    if(root->left==NULL && root->right==NULL && root->val==target){
        return NULL;
    }
    return root; 
}
TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return helper(root,target);
}
