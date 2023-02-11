//===類似題===
99. Recover Binary Search Tree
841. Keys and Rooms
1104. Path In Zigzag Labelled Binary Tree
339. Nested List Weight Sum


//===思路1====
(*)inorder概念
//=====
int helper1(TreeNode* root, long& pre){
    if(!root) return true;
    int l = helper1(root->left,pre);
    if(pre>=root->val) return false;//只有回傳此層, 上一層的上一層並沒有回傳這一層false,所以要在座後加上判斷描述 
    pre = root->val;
    int r = helper1(root->right, pre);
    return (l&&r)?true:false;//一直回傳到上層
}
void helper0(TreeNode* root, long& pre, int& res){
    if(!root) return;
    helper0(root->left, pre,res);
/*    if(pre==LONG_MIN) pre = root->val;
    if(pre>=root->val) res = false;
    else pre = root->val;*/
    if(root->val<=pre) res = false;//當下比較前一個
    pre = root->val;//紀錄前一個
/*    if(pre>=root->val) res = false;
    else pre = root->val;*/

    helper0(root->right,pre,res);
}
bool isValidBST(TreeNode* root){
    long pre = LONG_MIN;
    int res = true;
    helper0(root,pre,res);
    return res;
}

//===思路2===
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
