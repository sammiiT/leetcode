//===類似題==
200. Number of Islands
545. Boundary of Binary Tree

//===思路===
1.利用之前level-order trasversal的解法,求出每一個level的陣列
2.對每一個level的陣列的back()取出, 放入另外一個陣列, 此陣列就是right-size view

//======
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<vector<int>> res;
        vector<int> out;
        helper(root,0,res);
        
        for(int i=0;i<res.size();++i){
            
            out.push_back(res[i].back());
        }
        return out;
    }
    
    //利用level order, 將每一個level的數列列出來, 再將每一數列的最後一個數值取出
    void helper(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root) return;
        
        if(res.size()==level) res.push_back({});
        res[level].push_back(root->val);
        
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
    }
};
