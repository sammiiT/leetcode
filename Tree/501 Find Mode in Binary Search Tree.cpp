//===類似題===
502. IPO
582. Kill Process
341. Flatten Nested List Iterator
1376. Time Needed to Inform All Employees
//===思路===
(*)pre-order (DFS)
1.宣告unorderd_map<int,int>紀錄每一個數值出現的次數
2.遍歷tree, 將出現的數值出現的次數都記錄在unordered_map中
3.宣告一變數,紀錄出現"個數"的最大值

4.遍歷unordere_map<int,int>, 如果second==最大個數
-將first記錄到vector<int>中

//=====
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        int mx =INT_MIN;
        vector<int> res;
        helper(root,m,mx);
        for(auto a:m){
            if(a.second==mx){
                res.push_back(a.first);
            }
        }
        
        return res;
    }
    
    void helper(TreeNode* root,unordered_map<int,int>& m,int& mx){
        if(root==NULL) return;
    
        helper(root->left,m,mx);
        mx = max(mx,++m[root->val]);
        helper(root->right,m,mx);
    }
};

void helper(TreeNode* root, int& mval, unordered_map<int,int>& map){
        if(!root) return;
        
        map[root->val]+=1;
        mval = max(mval, map[root->val]);
        
        helper(root->left, mval, map);
        helper(root->right, mval, map);
}
    
    
vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> map;
        vector<int> res;
        int mval = 0;
        helper(root, mval, map);
        for(auto& it:map){
            if(it.second==mval){
                res.push_back(it.first);
            }
        }
        return res;
}
