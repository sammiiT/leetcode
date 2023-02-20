//===類似題===
939. Minimum Area Rectangle
1568. Minimum Number of Days to Disconnect Island
993. Cousins in Binary Tree
1257. Smallest Common Region
//===思路===
(*)pre-order (DFS)
 1.如果節點值 "大於等於" low, "小於等於" high
 -將其累加
//====
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        helper(root,L,R, res);
        return res;
    }
    void helper(TreeNode* root, int L, int R, int& res){
        if(!root) return;
        if(root->val >=L && root->val<=R){
            res+=root->val;
        }
        helper(root->left,L,R,res);
        helper(root->right,L,R,res);
    }
};

//===思路2===
(*)因為是BST所以遇到大於high或小於low的數值,就單獨對其做運算
(*)
if(root->val > high) helper0(root->left,low,high,res);//要做return的動作,不然會重複運算
if(root->val < low) helper0(root->right,low,high,res);
//=====
void helper0(TreeNode* root, int low, int high,int& res){
    if(!root) return;
    if(root->val > high) {//遇到大於high
        helper0(root->left,low,high,res);//往left方向移動
        return;//這邊要做return,不然會出錯
    }
    if(root->val < low) {//小於low
        helper0(root->right,low,high,res);//往right方向移動
        return;//要做return不然會重複運算
    } 
    res = res + root->val;
    helper0(root->left,low,high,res);
    helper0(root->right,low,high,res);
}
