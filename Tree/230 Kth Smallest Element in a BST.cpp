//===類似題===
231. Power of Two
1519. Number of Nodes in the Sub-Tree With the Same Label
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
173. Binary Search Tree Iterator
//===思路===
(*)方法1:(1-index) k遞減, 每操作一次,就遞減一次, 當k=0,代表執行k次.  => 概念背
(*)方法2: inoder遍歷tree,並用array紀錄每一個節點, 最後回傳array[k-1]即可

(*)in-order遍歷.
... 走到下一層的判斷式...       
inorder(root->left);
... 回到上一層的判斷式....
inorder(root->right);


//=====
void helper2(TreeNode* root, int& k, int& res){
        if(!root) return;
        helper2(root->left, k, res);
        if(k>=0) k--;//1-index  , 每次找到,做減1的動作, (k--)=>操作一次 ; 操作k次之後會等於零
        if(k==0) res=root->val;
        helper2(root->right, k, res);
}

void helper3(TreeNode* root, vector<int>& res){
    if(!root) return;
    helper2(root->left,res);
    res.push_back(root->val);//最後求[k-1]的數值,即是解    
    helper2(root->right,res);
}

void helper4(TreeNode* root, int& k, int& res){
    if(!root) return;
    if(k==0) return;//走到下一層的判斷式.
    helper4(root->left,k,res);
    if(k==0) return;//回到上一層時的判斷式
    if(k>0){
        --k;
        if(k==0){
            res = root->val;
            return;
        }
    }
    helper4(root->right,k,res);
}

//======
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int c=k;
        int count=0;
        
        // helper_2(root,k, count,res);
        helper(root,k,res);
        return res;
        
        
    }
    
    void helper(TreeNode* root, int& k, int& res){
        if(!root) return;
        helper(root->left,k,res);
        k--;
        if(k==0){
            res = root->val;
            return;
        }
        helper(root->right,k,res);
    }
    
    void helper_(TreeNode *node, int k, int& count, int& res){
        if(node==NULL) return;
        helper_(node->left, k, count, res);
        count+=1;
        if(count==k){
            res = node->val;
            return;
        }
        helper_(node->right, k, count,res);
    }
//=========================================    
    void helper(TreeNode* root, vector<int>& res){
        if(!root) return;
        
        helper(root->left,res);
        res.push_back(root->val);
        helper(root->right,res);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        helper(root,res);
        return res[k-1];
    }    
    
    
};
