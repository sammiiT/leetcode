//===類似題===
670. Maximum Swap
1306. Jump Game III
694. Number of Distinct Islands
298. Binary Tree Longest Consecutive Sequence
//===思路===
(*)post-order算法 (DFS)
1.如果root是在範圍之外,就將其刪除,
-刪除之後要將left和right重新連結並往上傳

(*) post-order計算時,回傳的節點, 要直接跟上一層的left或right做連接
root->left  = helper(root->left,low,high);
root->right = helper(root->right,low,high);

如果採用以下作法: 會發生錯誤, 因為"上層節點沒辦法連接到已經更改的下層節點"
TreeNode* l = helper(root->left,low,high);
TreeNode* r = helper(root->right,low,high);
//=====
TreeNode* helper(TreeNode* root, int low, int high) {
    if(!root) return NULL;
    root->left = helper(root->left,low,high);
    root->right = helper(root->right,low,high);
        
    if(root->val>high || root->val<low){  
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        if(l&&r){
            TreeNode* tmp = l;
            while(tmp->right) tmp = tmp->right;
            tmp->right = r;
            return l;        
        }else if(!l&&r){
            return r;
        }else if(l&&!r){
            return l;
        }else{//(!l&&!r)
            return NULL;
        }
    }
    return root;
}
TreeNode* trimBST(TreeNode* root, int low, int high){
    return helper(root,low,high);
}

//===思路2===
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        if(root->val > R) return trimBST(root->left,L,R);
        if(root->val < L) return trimBST(root->right,L,R);
        
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
        return root;
    }
    
    TreeNode* trimBST_OK(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        
        //binary search tree才可以用此方法
        if(root->val > R) return trimBST(root->left, L,R);
        
        //binary search tree才可以用此方法
        if(root->val < L) return trimBST(root->right, L, R);
            
        root->left = trimBST(root->left, L, R);
        root->right= trimBST(root->right, L, R);
        
        return root;
    }
};

//===思路3===
(*)post-order

TreeNode* helper0(TreeNode* root,int low, int high){
    if(!root) return NULL;
    root->left = helper0(root->left,low,high);
    root->right = helper(root->right,low,high);

    if(root->val>high || root->val<low){//是在[low,high]範圍之外
        if(!root->left && !root->right) return NULL;//如果節點沒有left和right子節點
        if(root->val>high && root->left) return root->left;//如果有left節點, 依據BST性質,回傳root->left
        if(root->val<low && root->right) return root->right;//如果有right節點, 依據BST性質,回傳root->right  
    }
    return root;//在[high,low]範圍之內, 直接回傳節點
}

//====用pre-order會錯誤===
(*)pre-order會錯誤, 因為在[low,high]範圍之內的節點可能在tree的很底層
-上層直接回傳之後, 沒有辦法算到底層的節點
[3,2,4,1]
low = 1
high = 1
=>最後回傳[2,4,1]; 2,4不在範圍內,所以錯誤
    
    
TreeNode* helper1(TreeNode* root, int low, int high){
    if(!root) return NULL;
    if(root->val<low || root->val>high){
        if(!root->left && !root->right) return NULL;
        if(root->val>high && root->left) return root->left;
        if(root->val<low && root->right) return root->right;   
    }
    root->left = helper(root->left,low,high);
    root->right = helper(root->right,low,high);
    return root;
}


