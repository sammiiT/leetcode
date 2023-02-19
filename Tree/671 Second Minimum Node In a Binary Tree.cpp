//===類似題===
672. Bulb Switcher II
510. Inorder Successor in BST II
1161. Maximum Level Sum of a Binary Tree
270. Closest Binary Search Tree Value
//===思路===
1.建立map<int,int>; <數值,次數>; map<int,int>型態會自動排列內部元素;對key作排列???
2.遍歷Tree
3.遍歷map,如果map有"兩個"或"兩個以上"
--第二個就是second minimum
//===
void helper0(TreeNode* root, map<int,int>& m){
    if(!root) return;
    m[root->val]++;
    helper0(root->left,m);   
    helper0(root->right,m);
}
int findSecondMinimumValue(TreeNode* root) {
    map<int,int> m;
    int i=0;
    int res = -1;
    helper0(root,m);
    
    for(auto a:m)
        if(++i==2) res = a.first;   
    return res; 
}

//===思路2

//====
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        long first = root->val, second = LONG_MAX;
        helper(root, first, second);
        // return (second == first || second == LONG_MAX) ? -1 : second;
        return (second==LONG_MAX)?-1:second;
    }
    
    void helper(TreeNode* node, long &first, long &second){
        if (!node) return;
    
        //用此運算是條件:數列是sort的狀態之下, Tree必須用pre-order方式
        //不是sort也可以用此運算
        if (node->val != first && node->val < second) {
            second = node->val;
        }
        helper(node->left, first, second);
        helper(node->right, first, second);
    }

    
};
