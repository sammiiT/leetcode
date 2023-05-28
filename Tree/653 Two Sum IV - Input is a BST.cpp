//===類似題===
654. Maximum Binary Tree
170. Two Sum III - Data structure design
1214. Two Sum BSTs
//===思路===
(*)pre-order 概念 + DFS
(*) helper(root->left,k,map)||helper(root->right,k,map);
-兩個路徑,left和right, 如果有一個滿足, 即可滿足

int helper(TreeNode* root, int k, unordered_map<int,int>& map){
    if(!root) return false;
    if(map.count(k-root->val)){
        return true;
    }else {
        map[root->val] = 1;
    }
   return helper(root->left,k,map)||helper(root->right,k,map);
}

bool findTarget(TreeNode* root, int k) {
    unordered_map<int,int> m;
    return helper(root,k,m);
}

//=======
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        int res = 0;
        unordered_map<int,int> m;
        // helper(root,k,m,res);
        helper_2(root,k,m,res);
        
        return res?true:false;
    }
    void helper(TreeNode* root,int k,unordered_map<int,int>& m,int& res){
        if(!root) return;
        
        helper(root->left,k,m,res);
        if(m.count(k-root->val)){
            res = 1;
            return;
        }
        m[root->val]++;
        
        helper(root->right,k,m,res);
    }
    void helper_2(TreeNode* root, 
                  int k, 
                  unordered_map<int,int>& m,
                  int &res){
        if(!root) return;
        if(m.count(k-root->val)){
            res =1;
            return;
        }
        m[root->val]++;
        helper(root->left,k,m,res);
        helper(root->right,k,m,res);
        
    }
};

