//===類似題===
99. Recover Binary Search Tree
841. Keys and Rooms
1104. Path In Zigzag Labelled Binary Tree
339. Nested List Weight Sum

//===思路===
(*)pre-order概念
-每一個節點都去跟左右兩端的極大,極小值做比較; 
-如果當下節點滿足上述搜尋條件,則往下一個節點繼續找 
-如果不滿足,則回傳false, 中斷搜尋(不再往下找)
-可以找到最後一個節點, 則回傳true

//==========
class Solution {
public:
    bool isValidBST(TreeNode *root){
        if(!root) return true;
        if(root->left && root->val<=MaxValue(root->left)) return false;
        if(root->right && root->val>=MinValue(root->right)) return false;
        return isValidBST(root->left)&&isValidBST(root->right);
    }
    bool isValidBST_OK(TreeNode* root) {
        if(root==NULL) return true;
        //沒有root->left項, 在maxValue會發生NULL pointer
        if(root->left && root->val<=maxValue(root->left))
            return false;
        //沒有root->right項, 在minValue會發生NULL pointer
        if(root->right && root->val>=minValue(root->right))    
            return false;
        
        return isValidBST(root->left) && isValidBST(root->right);    
    }
    
    int minValue(TreeNode *root){
        if(root->left) return minValue(root->left);
        else return root->val;
    }
    
    int maxValue(TreeNode *root){
        if(root->right) return maxValue(root->right);
        else return root->val;
    }
    
    
    int MinValue(TreeNode *root){
        while(true){
            if(root->left) root= root->left;
            else return root->val;
        }
    }
    int MaxValue(TreeNode *root){
        while(true){
            if(root->right) root=root->right;
            else return root->val;
        }
    }
};
