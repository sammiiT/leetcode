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
                  vector<int> out,//此方式會造成較大的stack,每次遞迴進入都會copy一次vector
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
     
    void helper(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& v){
        if(!root) return;
        v.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum-root->val==0){
                res.push_back({});
                for(int i=0; i<v.size(); i++)
                    res[res.size()-1].push_back(v[i]);
            }
        }
        if(root->left) helper(root->left, targetSum-val, res, v);
        if(root->right) helper(root->right,targetSum-val, res, v);
        v.pop_back();
    }     
     
     
};
