class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> out;
        if(root==NULL) return 0;
        helper(root,sum,0,out,res);
        return res;
    }
    
    void helper(TreeNode *root, 
                int sum, 
                int curSum,
                vector<TreeNode*>& out,
                int& res){
        
        if(root==NULL) return;
    
        curSum+=root->val;
        if(curSum==sum) res++;
        
        out.push_back(root);
        int tmp = curSum;
        for(int i=0;i<out.size()-1;++i){
            tmp = tmp-out[i]->val;
            if(tmp==sum) res++;
        }
        
        helper(root->left,sum,curSum,out,res);
        helper(root->right, sum, curSum,out,res);
        
        out.pop_back();
    }
    
    
};