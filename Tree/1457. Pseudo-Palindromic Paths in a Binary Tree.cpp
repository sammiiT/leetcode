//===類似題======
1644. Lowest Common Ancestor of a Binary Tree II
2385. Amount of Time for Binary Tree to Be Infected
2359. Find Closest Node to Given Two Nodes

bool canCreatePalindrome(unordered_map<int,int>& m){
        int odd=0;
        for(auto a:m){
           if(a.second%2){
              if(++odd>1) return false;
           }
        }
        return true;
}
void helper0(TreeNode* root,unordered_map<int,int>& m,int& res){
        if(!root) return;

        m[root->val]++;
        if(!root->left && !root->right){
            res+=canCreatePalindrome(m);        
        }
        helper0(root->left,m,res);
        helper0(root->right,m,res);
        m[root->val]--;
}
int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> m;
        int res = 0;
        helper0(root,m,res);
        return res;
}
