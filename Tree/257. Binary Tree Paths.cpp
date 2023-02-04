//===類似題===
258. Add Digits
988. Smallest String Starting From Leaf
2096. Step-By-Step Directions From a Binary Tree Node to Another
//===思路===
(*)pre-order算法 (DFS)

(*)小技巧: stack概念, 因為每次丟入下一層的參數會用新的stack
-所以"->"作為下一次帶入的參數
-從下一層return回上一層,"->"就不會存在於陣列中
  
//======
void helper(TreeNode* root, string s ,vector<string>& res){
    if(!root) return;

    s+=to_string(root->val);
    if(!root->left && !root->right){
        res.push_back(s); 
        return;
    }
    helper(root->left,s+"->",res);//s+"->"帶入下一層, return時不會影響陣列的內容
    helper(root->right,s+"->",res);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> res;
        helper(root, s, res);
        return res;
    }
