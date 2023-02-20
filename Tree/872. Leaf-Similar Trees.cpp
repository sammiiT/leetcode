//===類似題===
873. Length of Longest Fibonacci Subsequence
1120. Maximum Average Subtree
1254. Number of Closed Islands
2313. Minimum Flips in Binary Tree to Get Result
//===思路===
(*)pre-order算法 (DFS)
1. 設定一函式,功能為求出最底端的leaf排列
2.將root1和root2分別帶入此函式中, 可得到個別的leaf陣列
3.比較兩leaf,即為解

(*)比較可用vector<int> 或 string
//====
//string解法
void helper(TreeNode* root, string& str){
    if(!root) return;
    if(!root->left && !root->right){
        str+=to_string(root->val)+",";//要加上,做區隔,沒有此逗號會有錯誤
        return;
    }
    helper(root->left,str);
    helper(root->right,str);
}
//用vector解法
void helper(TreeNode* root, vector<int>& res){
    if(!root) return;
    if(!root->left && !root->right){
        res.push_back(root->val);
        return;
    }
    helper(root->left,res);
    helper(root->right,res);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string leaf1,leaf2;
        helper(root1,leaf1);
        helper(root2,leaf2);
        return (leaf1==leaf2);
}
//===思路2===
(*)pre-order + return value
(*) 有return value區注意, 因為bottom leaf一樣,但tree的level有可能不一樣;這樣會導致遇到NULL node時的return 排列
(*) 如果 if(!root) return "*,"; 會因為tree的level不一樣,而產生不同的string,如下:
     1             1
    / \           / \
   2   x         3   x
  / \
 3   x
 
(*)所以當遇到NULL節點, 回傳 "空" string
-- return "";
//===
string aaa(TreeNode* root){
    if(!root) return "";
    string s;
    if(!root->left &&!root->right){
        s = to_string(root->val)+",";
    }
    string sl = aaa(root->left);
    string sr = aaa(root->right);
    return s+sl+sr;
}







