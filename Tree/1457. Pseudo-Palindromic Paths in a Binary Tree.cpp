//===類似題======
1644. Lowest Common Ancestor of a Binary Tree II
2385. Amount of Time for Binary Tree to Be Infected
2359. Find Closest Node to Given Two Nodes

//=====思路====
(*)pre-order遍歷
1. 當遇到最後一個節點時, 計算是否可以形成palindrome
2. 每進入下一層, 都將結點值紀錄在unordered_map<int,int>中; 用來判斷數值出現的次數
3. 每次回上一層,就將map中對應的數值"刪除"
- 刪除可減少判斷palindrome時的運算次數

3. 每次回上一層,就將map中對應的數值"減一"
- 減一,當對應數值等於零, 仍然會在判斷palindrome中做計算... 所以運算時間會加長
//=====
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
//===優化====
void helper1(TreeNode* root, unordered_map<int,int>& mp, int& res){

    ++mp[root->val];
    if(!root->left&&!root->right) res+=canCreatePalindrome(mp);
    
    helper1(root->left,mp,res);
    helper1(root->right,mp,res);
    
    //將只有出現過一次的數值從map中清除, 才不會在canCreatePalindrome中計算
    if(mp[root->val]==1) mp.erase(root->val);
    else --mp[root->val];
}
