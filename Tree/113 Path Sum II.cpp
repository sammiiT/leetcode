class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
         helper(root,sum,out,res);
        // helper_2(root,sum,out,res);
        return res;
    }
    
    void helper(TreeNode *root,
               int sum,
               vector<int> &out,
               vector<vector<int>>& res){
        if(!root) return;
        
        out.push_back(root->val);
        if(!root->left && !root->right){
            sum=sum-root->val;
            if(sum==0) res.push_back(out);
        }else{
            helper(root->left,sum-root->val,out,res);
            helper(root->right,sum-root->val,out,res);
        }
        out.pop_back();
    }
    
    
    
    void helper_2(TreeNode* root, 
                  int sum, 
                  vector<int> out,
                  vector<vector<int>>& res){
        if(!root) return;
        
        out.push_back(root->val);
        if(!root->left && !root->right){
            sum-=root->val;
            if(sum==0){
                res.push_back(out);
                return;
            }else{
                return;
            }
        }else{
            helper_2(root->left,sum-root->val,out,res);
            helper_2(root->right,sum-root->val,out,res);
        }
        
        
    }
    
    
    void helper_3(TreeNode *root,
               int sum,
               vector<int> &out,
               vector<vector<int>>& res){
        if(root==NULL) return;
        
        sum = sum-root->val;
        out.push_back(root->val);
        
        if(!root->left && !root->right){
            if(sum==0){
                res.push_back(out);
                out.pop_back();
                return;
            }else{
                out.pop_back();
                return;
            }
        }else{
            helper(root->left,sum,out,res);
            helper(root->right,sum,out,res);
        }
        out.pop_back();
    }
};