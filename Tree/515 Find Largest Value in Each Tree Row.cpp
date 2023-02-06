//===類似題===
516. Longest Palindromic Subsequence
1202. Smallest String With Swaps
2328. Number of Increasing Paths in a Grid
841. Keys and Rooms
//===思路===
(*)level-order trasversal (DFS)
(*)將之前2D換成1維陣列
-每次到相同level,則用max(x,y)來決定當下的數值
-最後求出的1維陣列,即為解
//=====
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;
    }
    
    
    void helper(TreeNode *root, int level, vector<int>& res){
        if(!root) return;
        if(res.size()==level) res.push_back(INT_MIN);
        res[level] = max(res[level],root->val);
        
        helper(root->left, level+1, res);
        helper(root->right, level+1, res);
    }
};

void helper(TreeNode* root, int level, vector<int>& res){
        if(!root) return;
        
        if(level==res.size()){
            res.push_back({});  
            res[level] = root->val;
        }else{
            res[level] = max(res[level],root->val);
        } 
        
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
}   
vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        
        return res;
}
