//===類似題===
113. Path Sum II
666. Path Sum IV
//===思路===
(*)pre-order (DFS)
1.先計算累加
2.判斷是不是最後一個節點, ->left和->right都是NULL, 如果是最後一個節點,就判斷是不是等於targetSum
3.如果等於targetSum, 就回傳true
4.不是最後一個節點, 就繼續往下一層計算

5.往下一層計算要用(左節點 || 右節點), 只要左右兩邊有一個等於targetSum, 就回傳true

(*)如果子節點只有一個,他的下一層會有一個會回傳false.
//====
bool helper0(TreeNode* root, int targetSum, int res){//用加法
    if(!root) return false;
    res+=root->val;
    if(!root->left && !root->right){
        if(res==targetSum) return true;
        return false;
    }
    return helper0(root->left,targetSum,res) || helper0(root->right,targetSum,res);
}

bool helper1(TreeNode * root, int targetSum){//用減法
    if(!root) return false;
    targetSum-=root->val;
    if(!root->left && !root->right){
        if(targetSum==0) return true;
        return false;
    }
    return helper1(root->left,targetSum)||helper1(root->right,targetSum);
}


//=====
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        
        if(!root->left && !root->right){
            sum = sum -root->val;
            if(sum==0)return true;
            else return false;
        }else{
			//root->left==NULL || root->right!=NULL
			//root->left!=NULL || root->right==NULL
			//root->left!=NULL || root->right!=NULL
            return hasPathSum(root->left,sum-root->val)||
                hasPathSum(root->right,sum-root->val);
        }
    }
    // void helper(TreeNode* root, int sum, vector<int>& out)
};
