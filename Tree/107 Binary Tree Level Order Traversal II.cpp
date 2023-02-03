//===類似題===
108. Convert Sorted Array to Binary Search Tree
499. The Maze III
366. Find Leaves of Binary Tree
1485. Clone Binary Tree With Random Pointer

//===思路====
(*)pre-order 算法 (DFS)
1.將每一個order的數加入vetor<vector<int>>中
2.最後再對vetor<vector<int>>做reverse

//====
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res = {};
        int level = 0;
        helper(root,level,res);
        
        reverse(res.begin(),res.end());
        return res;
        // return vector<vector<int>>(res.rbegin(),res.rend());
    }
    
    void helper(TreeNode* root, int level, vector<vector<int>> &res){
        if(root==NULL) return;
        
        if(res.size()==level) res.push_back({});
        
        res[level].push_back(root->val);
        level+=1;
        helper(root->left,level,res);
        helper(root->right,level,res);
    }
};
