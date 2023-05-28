//===類似題===
1469. Find All The Lonely Nodes
170. Two Sum III - Data structure design
545. Boundary of Binary Tree
2133. Check if Every Row and Column Contains All Numbers

同1123. Lowest Common Ancestor of Deepest Leaves
//===思路===
(*)smallest subtree with deepest node
- 如果有兩個以上的deepest node, 則要找到其common ancestor
- 如果只有一個deepsett node, 只要回傳此deepest node; 

(*)利用maxDepth
-判斷左右path的maxDepth是否相等, 如果相等,則回傳此level的root節點
-如果不相等, 就往下一個節點做運算, 下一個節點的選取, 選擇dpeth最長的的那一個節點
-只有一個deepest node, 則最後的判斷會 node->left==NULL, node->right==NULL, if(diff==0) return root;//此root是deepest node
====
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root){
        
        int diff = maxDepth(root->left)-maxDepth(root->right);
        return (diff==0)? root: subtreeWithAllDeepest(diff>0?root->left:root->right);
    }
    
    TreeNode* subtreeWithAllDeepest_ok(TreeNode* root) {
        int diff = maxDepth(root->left) - maxDepth(root->right);
        
        if(diff==0) return root;//
        else if(diff>0){
            return subtreeWithAllDeepest(root->left);//左邊比較深
            
        }else{//diff<0
            return subtreeWithAllDeepest(root->right);//右邊比較深
        }
    }
    int maxDepth(TreeNode* root){
        return (!root)? 0: max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    
    int maxDepth_ok(TreeNode* root){
        if(!root) return 0;
        
        int l=0,r=0;
        if(root->left) l = maxDepth(root->left);
        if(root->right)r = maxDepth(root->right);
        
        return 1+max(l,r);
    }
};
